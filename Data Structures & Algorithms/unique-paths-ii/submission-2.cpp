class Solution {
public:
    int m;
    int n;

    int tabulation(vector<vector<int>>&obstacleGrid){
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();

        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));

        // dp[i][j] = number of unique paths from (i,j) to (m-1,n-1)

        //destination itself is blocked
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;

        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                if(i==m-1 && j==n-1) continue;

                //no path can start from an obstacle
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }

                long long down=0;
                if(i+1<m){
                    down=dp[i+1][j];
                }

                long long right=0;
                if(j+1<n){
                    right=dp[i][j+1];
                }

                dp[i][j]=down+right;
            }
        }

        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return tabulation(obstacleGrid);
    }
};