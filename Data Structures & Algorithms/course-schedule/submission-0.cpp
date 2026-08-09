class Solution {
public://cycle detection->BFS( KAHN'S ALGO) topo sort.

    int bfs(vector<vector<int>>&adj,vector<int>&indegree,int n){
        queue<int>q;

        //push all courses having indegree =0;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            count++;

            //remove current node's dependency from neighbours
            for(auto &nbr:adj[node]){
                indegree[nbr]--;

                 // If all prerequisites are completed
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        // Return number of courses successfully processed
        return count;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        // [a,b] means first complete b, then a
        // edge: b -> a

        for(auto &p:prerequisites ){
            int a=p[0];
            int b=p[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        int count=bfs(adj,indegree,numCourses);

        // If every course was processed -> no cycle
        if(count==numCourses) return true;

        // Some courses could not be processed -> cycle exists
        else return false;
    }
};