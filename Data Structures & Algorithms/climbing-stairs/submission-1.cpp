class Solution {
public:
    int memoisation(int n,vector<int>&dp){
        //base case
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];
        //take 1 step
        int oneStep=0;
        oneStep+=memoisation(n-1,dp);

        //take 2 step
        int twoStep=0;
        twoStep+=memoisation(n-2,dp);

        return dp[n]= oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return memoisation(n,dp);
    }
};