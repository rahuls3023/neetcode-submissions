class Solution {
public: // using set instead of priority queue, rest logic is same.
    unordered_map<int, int> shortestPath(
        int V,
        vector<vector<int>>& edges,
        int src
    ) {

        // Adjacency list:
        // adj[u] stores pairs of {neighbour, edgeWeight}
        vector<vector<pair<int, int>>> adj(V);

        // Build adjacency list from edge list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // Directed graph
            adj[u].push_back({v, wt});
        }

        set<pair<int, int>> st;

        // dist[i] stores the shortest distance
        // found so far from source to node i
        vector<int> dist(V, INT_MAX);

        // Distance from source to itself is 0
        dist[src] = 0;

        // insert {distance, node}
        st.insert({0, src});

        while (!st.empty()) {

            // Get the node having minimum distance
            auto it = st.begin();

            int currDist = it->first;
            int node = it->second;

            st.erase(it);

            // Traverse all neighbours of the current node
            for (auto& nbr : adj[node]) {

                int adjNode = nbr.first;
                int edgeWeight = nbr.second;

                // New possible distance:
                // source -> current node -> adjacent node
                int newDist = currDist + edgeWeight;

                // Relaxation:
                // Update only when a shorter path is found
                if (newDist < dist[adjNode]) {

                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = newDist;

                    // Push updated distance into set
                    st.insert({newDist, adjNode});
                }
            }
        }

        unordered_map<int, int> answer;

        // Convert the distance vector into a map:
        // node -> shortest distance from source
        for (int node = 0; node < V; node++) {

            // If node is unreachable from source
            if (dist[node] == INT_MAX) {
                answer[node] = -1;
            } else {
                answer[node] = dist[node];
            }
        }

        return answer;
    }
};