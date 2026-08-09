class Solution {
public://cycle detection->dfs topo sort.
     bool isCycleDfs(int node,vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& pathVisited){

        visited[node] = true;
        pathVisited[node] = true;

        for(int nbr:adj[node]){
            //if nbr is not visited, explore it

            if(visited[nbr]==false){
                if(isCycleDfs(nbr,adj,visited,pathVisited))
                return true;
            }

            //if neighbour is already in current dfs path-> cycle detected
            else if(pathVisited[nbr]==true){
                return true;
            }
            // If visited but not in current path,
            // then this edge does not form a cycle
        }
         // Backtrack: remove current node from current DFS path
        pathVisited[node] = 0;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        // [a,b] means first complete b, then a
        // edge: b -> a

        for(auto &p:prerequisites ){
            int a=p[0];
            int b=p[1];

            adj[b].push_back(a);
        }

        vector<bool>visited(numCourses,false);
        vector<bool>pathVisited(numCourses,false);

       for(int i=0;i<numCourses;i++){
            if(!visited[i] && isCycleDfs(i,adj,visited,pathVisited)==true){
                return false;
            }
       }
       return true;
    }
};