class Solution {
public:
    int memoisation(int index,int canBuy,vector<int>&prices,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;

        if(dp[index][canBuy]!=-1) return dp[index][canBuy];

        // dp[index][canBuy] = maximum profit we can make from index to n-1,
        // where canBuy tells whether we can buy a stock or not

        //means we can buy on this index
        //we can either buy today or skip buying today
        if(canBuy==1){
            int buytoday=-prices[index]+memoisation(index+1,0,prices,dp);

            int skipBuyToday=memoisation(index+1,1,prices,dp);

            return dp[index][canBuy]= max(buytoday,skipBuyToday);
        }
        else{
            //means we already have some stocks, we need to sell it
            //we can either sell today or skip sell today

            int sellToday=prices[index]+memoisation(index+1,1,prices,dp);

            int skipSellToday=memoisation(index+1,0,prices,dp);

            return dp[index][canBuy]= max(sellToday,skipSellToday);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return memoisation(0,1,prices,dp);
    }
};