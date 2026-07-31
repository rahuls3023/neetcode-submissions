class Solution {
public:
    unordered_map<int, int> shortestPath(
        int n,
        vector<vector<int>>& edges,
        int src
    ) {
        // Adjacency list:
        // adj[u] stores {destination node, edge weight}
        vector<vector<pair<int, int>>> adj(n);

        // Build adjacency list for directed graph
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // Directed edge: u -> v with weight wt
            adj[u].push_back({v, wt});
        }

        // Min heap storing {distance from source, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // dist[i] stores the shortest distance
        // found so far from src to node i
        vector<int> dist(n, INT_MAX);

        // Distance from source to itself is 0
        dist[src] = 0;

        // Push {distance, node}
        pq.push({0, src});

        while (!pq.empty()) {

            // Get the node having minimum distance
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated heap entries
            if (currDist != dist[node]) {
                continue;
            }

            // Traverse all outgoing neighbours
            for (auto& nbr : adj[node]) {

                int adjNode = nbr.first;
                int edgeWeight = nbr.second;

                // New possible distance:
                // src -> current node -> adjacent node
                int newDist = currDist + edgeWeight;

                // Relaxation:
                // Update when a shorter path is found
                if (newDist < dist[adjNode]) {

                    dist[adjNode] = newDist;

                    // Push updated distance into min heap
                    pq.push({newDist, adjNode});
                }
            }
        }

        // Store final shortest distances in map
        unordered_map<int, int> answer;

        for (int node = 0; node < n; node++) {

            // If node is unreachable from source
            if (dist[node] == INT_MAX) {
                answer[node] = -1;
            }
            else {
                // Node is reachable, store its shortest distance
                answer[node] = dist[node];
            }
        }

        return answer;
    }
};