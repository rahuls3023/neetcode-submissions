class Solution {
public://dfs-> count number of connected components

    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1' || visited[i][j]==true) return;

        visited[i][j]=true;
        
        dfs(grid,i+1,j,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i,j+1,visited);
        dfs(grid,i,j-1,visited);
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
                    dfs(grid,i,j,visited);
                }
            }
        }
        return island;
    }
};