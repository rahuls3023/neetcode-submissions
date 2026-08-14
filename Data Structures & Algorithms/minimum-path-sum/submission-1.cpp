class Solution {
public:
    int m;
    int n;
    int memoisation(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){

        // dp[i][j] = minimum path sum from (i,j) to (m-1,n-1)

        if(dp[i][j]!=-1) return dp[i][j];

        if(i>=m || j>=n) return 0;

        if(i==m-1 && j==n-1) return grid[m-1][n-1];

        int right=INT_MAX;
        if(j+1<n){
            right=grid[i][j]+memoisation(i,j+1,grid,dp);
        }

        int down=INT_MAX;
        if(i+1<m){
            down=grid[i][j]+memoisation(i+1,j,grid,dp);
        }

        return dp[i][j]= min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memoisation(0,0,grid,dp);
    }
};