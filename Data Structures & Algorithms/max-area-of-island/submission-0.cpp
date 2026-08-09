class Solution {
public://bfs approach
    vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};

    int bfs(vector<vector<int>>&grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();

        int area=0;

        queue<pair<int,int>>q;
        grid[i][j]=0;//mark visited
        q.push({i,j});

        while(!q.empty()){
            auto current=q.front();
            q.pop();
            area++;

            for(auto &dir:directions){
                int newr=current.first+dir[0];
                int newc=current.second+dir[1];

                if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc]==1){
                    grid[newr][newc]=0;

                    q.push({newr,newc});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        int maxArea=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,bfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};