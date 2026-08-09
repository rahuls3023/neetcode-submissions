class Solution {
public://bfs-> count number of connected components
    vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};

    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&visited){
        visited[i][j]=true;
         int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            auto current=q.front();
            q.pop();

            int r=current.first;
            int c=current.second;

            for(auto &dir:directions){
                int new_r=r+dir[0];
                int new_c=c+dir[1];

                if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && !visited[new_r][new_c] && grid[new_r][new_c]=='1'){
                    q.push({new_r,new_c});
                    visited[new_r][new_c]=true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int island=0;

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    island++;
                    bfs(grid,i,j,visited);
                }
            }
        }
        return island;
    }
};