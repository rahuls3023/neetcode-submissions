class Solution {
public:
    vector<int>bfs(vector<vector<int>>&adj,vector<int>&indegree,int numCourses){
        queue<int> q;
        vector<int> ans;

        // Push all courses having indegree 0
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();

             // Store course in topological order
            ans.push_back(node);

            for(auto &nbr:adj[node]){
                indegree[nbr]--;

                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //bfs approach-> jaise jaise indegree 0 hote rhe ans me push krte rho node, us order me courses finish krne h.

         vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // [a,b] means b should be completed before a
        // edge: b -> a
        for(auto &p : prerequisites){

            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        vector<int> ans = bfs(adj, indegree, numCourses);

        // if all courses are present, valid ordering exists
        if(ans.size() == numCourses)
            return ans;

        // cycle exists
        return {};

    }
};