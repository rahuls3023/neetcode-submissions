class Solution {
public:
    int memoisation(int index,vector<int>&cost,vector<int>&dp){
        if(index>=cost.size()){
            return 0;
        }

        if(dp[index]!=-1) return dp[index];

        //either 1 step or 2 step
        int oneStep=0;
        oneStep+=cost[index]+memoisation(index+1,cost,dp);

        int twoStep=0;
        twoStep+=cost[index]+memoisation(index+2,cost,dp);

        return dp[index]= min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        vector<int>dp(n+1,-1);

        int startFromIndex0=memoisation(0,cost,dp);

        int startFromIndex1=memoisation(1,cost,dp);

        return min(startFromIndex0,startFromIndex1);
    }
};