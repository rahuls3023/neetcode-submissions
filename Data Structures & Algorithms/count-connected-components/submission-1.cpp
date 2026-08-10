class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;

        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                dfs(nbr,adj,visited);
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
                dfs(i,adj,visited);
                components++;
            }
        }

        return components;
    }
};
