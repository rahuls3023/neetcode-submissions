class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathVisited,vector<int>&ans){
        visited[node] = true;
        pathVisited[node] = true;

        for(int nbr:adj[node]){
            // Case 1: not visited -> explore
            if(visited[nbr] == false){

                if(dfs(nbr, adj, visited, pathVisited, ans))
                    return true;
            }

            //agar nbr pehle se visited h and current path me bhi hai-> cycle detected
            else if(visited[nbr] == true &&
                    pathVisited[nbr] == true){

                return true;
            }

            //agar nbr visited to h but current path me nhi h-> nothing to do
        }

        // Remove node from current DFS path
        pathVisited[node] = false;

        // Push after exploring all neighbours
        ans.push_back(node);

        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);

        // [a,b] means b must be completed before a
        // edge: b -> a
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        vector<int> ans;

        //graoh can have multiple components
        for(int i=0;i<numCourses;i++){
            if(visited[i]==false){
                  // Cycle exists -> no valid course ordering
                if(dfs(i, adj, visited, pathVisited, ans))
                    return {};
            }
        }
          // DFS produces reverse topological order becuase of stack.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};