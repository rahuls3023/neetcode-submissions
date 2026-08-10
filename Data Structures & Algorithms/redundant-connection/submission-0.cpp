class Solution {
public:
    bool dfs(int node,int target,vector<vector<int>>&adj,vector<bool>&visited){
        if(node==target) return true;//we can reach this node

        visited[node] = true;

        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                if(dfs(nbr,target,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // add edges 1 by 1
        //before adding edge between [u,v] check if v is reacheable from u or not.
        //if it is reachable then adding edge will create cycle.
        //orherwise add edge

        int n=edges.size();

        vector<vector<int>>adj(n+1);//nodes are from 1 to n

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            vector<bool>visited(n+1,false);

            //if we can already visit v , adding this edge will create cycle
            if(dfs(u,v,adj,visited)){
                return e;
            }
            
            //otherwise add edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
