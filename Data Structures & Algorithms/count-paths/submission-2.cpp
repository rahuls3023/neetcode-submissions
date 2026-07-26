class Solution {
public:
    int tabulation(int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        // dp[i][j] = number of unique paths from cell (i, j)
        // to the destination cell (m-1, n-1).

        // Base case:
        // From the destination itself, there is exactly one path
        // (we are already at the destination).
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;

                //we can have two options

                int down=dp[i+1][j];

                int right=dp[i][j+1];

                dp[i][j]=down+right;
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        
        return tabulation(m,n);
    }
};