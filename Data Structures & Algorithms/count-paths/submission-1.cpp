class Solution {
public:
    int memoisation(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i<0 || i>=m || j<0 || j>=n) return 0;

        if(i==m-1 && j==n-1){
            return 1;
        } 

        //dp[i][j]=number of unique paths to reach the destination from i and j index

        if(dp[i][j]!=-1) return dp[i][j];

        //we can have two options

        int down=memoisation(i+1,j,m,n,dp);

        int right=memoisation(i,j+1,m,n,dp);

        return dp[i][j]=(down+right);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memoisation(0,0,m,n,dp);
    }
};