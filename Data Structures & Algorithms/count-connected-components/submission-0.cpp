class Solution {
public:
    void bfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto nbr:adj[node]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components=0;

        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,adj,visited);
                components++;
            }
        }

        return components;
    }
};
