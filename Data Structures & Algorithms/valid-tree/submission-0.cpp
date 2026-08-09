class Solution {
public:
    // Valid tree ke liye exactly 2 cheezein-->:
    // No cycle
    // All n nodes connected

    //undirected graph cycle-> visited+parent.

    bool isCycle(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;

        for(int nbr:adj[node]){
            //if nbr is not visited , explore it
            if(visited[nbr]==false){
                if(isCycle(nbr,node,adj,visited)) return true;//cycle detected
            }
            //nbr already visited hai, aur wo current node ka parent nahi hai → cycle. 
             else if(nbr!=parent){
                return true;
            }
        }
        //no cycle found
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size()!=n-1) return false;

        vector<vector<int>>adj(n);

         // Build undirected graph
        for(auto &edge : edges){

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        if(isCycle(0,-1,adj,visited)) return false;//agar cycle milgyi

        //check all nodes visited hue ya nhi
         for(int i=0; i<n; i++){

            if(visited[i] == false)
                return false;
        }

        // No cycle + connected
        return true;
    }
};
