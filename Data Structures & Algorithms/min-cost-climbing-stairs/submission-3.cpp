class Solution {
public:
    int tabulation(vector<int>&cost){
        int n=cost.size();

        vector<int>dp(n+2,0);

        for(int index=n-1;index>=0;index--){
            int oneStep=0;
            oneStep+=cost[index]+dp[index+1];

            int twoStep=0;
                twoStep=cost[index]+dp[index+2];

            dp[index]=min(oneStep,twoStep);
        }
        return min(dp[0],dp[1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {

        return tabulation(cost);
    }
};