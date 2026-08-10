class Solution {
public:
    vector<int>dijkstra(int src,int n,vector<vector<pair<int,int>>>&adj){

          // dist[i] = shortest distance from src to node i
        vector<int> dist(n + 1, INT_MAX);

        // Min heap stores {distance, node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        dist[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            int currentDistance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            //skip outdated entry
            if(currentDistance>dist[node]){
                continue;
            }
            //explore all nbrs
            for(auto &p:adj[node]){

                int nbr=p.first;
                int nbrdist=p.second;

                if(nbrdist+currentDistance<dist[nbr]){
                    dist[nbr]=nbrdist+currentDistance;

                    pq.push({dist[nbr],nbr});
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto t:times){
            int u=t[0];
            int v=t[1];
            int wt=t[2];

            adj[u].push_back({v,wt});
        }

         // Find shortest distance from k to every node
        vector<int> dist = dijkstra(k, n, adj);

         int ans = 0;

        // Network delay = maximum shortest distance
        // among all nodes

        for(int i=1;i<=n;i++){
             // This node cannot be reached from k
            if(dist[i] == INT_MAX) {
                return -1;
            }
            ans=max(ans,dist[i]);

        }
        return ans;
    }
};