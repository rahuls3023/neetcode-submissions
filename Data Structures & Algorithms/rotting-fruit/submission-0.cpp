class Solution {
public:

    vector<vector<int>> directions = {
        {1,0},{-1,0},{0,1},{0,-1}
    };

    int bfs(vector<vector<int>>& grid, int &fresh, queue<pair<int,int>>& q){
        int m = grid.size();
        int n = grid[0].size();

        int minutes = 0;

        while(!q.empty()){

            // Current queue size represents oranges rotten at the same time level
            int size = q.size();

            // Used to check whether any new fresh orange became rotten
            bool rottenNew = false;

            // Process one complete BFS level = one minute
            for(int i = 0; i < size; i++){

                auto current = q.front();
                q.pop();

               
                for(auto &dir : directions){

                    int newr = current.first + dir[0];
                    int newc = current.second + dir[1];

                    // If neighbour is inside grid and is a fresh orange
                    if(newr >= 0 && newr < m &&
                       newc >= 0 && newc < n &&
                       grid[newr][newc] == 1){

                        // Make this fresh orange rotten
                        grid[newr][newc] = 2;
                        fresh--;

                        rottenNew = true;

                        q.push({newr,newc});
                    }
                }
            }

            // Increase time only if at least one new orange became rotten
            if(rottenNew)
                minutes++;
        }

        return minutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int fresh = 0;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // Count fresh oranges and push all initially rotten oranges into queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        // No fresh oranges means no time is required
        if(fresh == 0)
            return 0;

        int minutes = bfs(grid, fresh, q);

        // If all fresh oranges became rotten
        if(fresh == 0)
            return minutes;

        // Some fresh oranges were unreachable
        return -1;
    }
};