class Solution {
public:
    int m;
    int n;
    int memoisation(int i,int j,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n || obstacleGrid[i][j]==1) return 0;

        // dp[i][j] = number of unique paths from (i,j) to (m-1,n-1)

        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int down=0;
        if(i+1<m){
            down=memoisation(i+1,j,obstacleGrid,dp);
        }

        int right=0;
        if(j+1<n){
            right=memoisation(i,j+1,obstacleGrid,dp);
        }

        return dp[i][j]= down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memoisation(0,0,obstacleGrid,dp);
    }
};