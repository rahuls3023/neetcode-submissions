class Solution {
public:
    int m;
    int n;
    int tabulation(vector<vector<int>>&grid){
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        dp[m-1][n-1]=grid[m-1][n-1];

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                if(i==m-1 && j==n-1) continue;

                int right=INT_MAX;
                if(j+1<n){
                    right=grid[i][j]+dp[i][j+1];
                }

                int down=INT_MAX;
                if(i+1<m){
                    down=grid[i][j]+dp[i+1][j];
                }

                dp[i][j]= min(right,down);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return tabulation(grid);
    }
};