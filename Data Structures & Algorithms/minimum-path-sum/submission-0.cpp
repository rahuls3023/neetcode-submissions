class Solution {
public:
    int m;
    int n;
    int recursion(int i,int j,vector<vector<int>>&grid){
        if(i>=m || j>=n) return 0;

        if(i==m-1 && j==n-1) return grid[m-1][n-1];

        int right=INT_MAX;
        if(j+1<n){
            right=grid[i][j]+recursion(i,j+1,grid);
        }

        int down=INT_MAX;
        if(i+1<m){
            down=grid[i][j]+recursion(i+1,j,grid);
        }

        return min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        return recursion(0,0,grid);
    }
};