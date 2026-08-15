class Solution {
public:

    int tabulation(vector<int>&prices){
        int n=prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,0));

        // dp[index][canBuy] = maximum profit we can make from index to n-1,
        // where canBuy tells whether we can buy a stock or not

        for(int index=n-1;index>=0;index--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                if(canBuy==1){
                int buytoday=-prices[index]+dp[index+1][0];

                int skipBuyToday=dp[index+1][1];

                dp[index][canBuy]= max(buytoday,skipBuyToday);
                }
                else{
                    //means we already have some stocks, we need to sell it
                    //we can either sell today or skip sell today

                    int sellToday=prices[index]+dp[index+1][1];

                    int skipSellToday=dp[index+1][0];

                    dp[index][canBuy]= max(sellToday,skipSellToday);
                }
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
    
        return tabulation(prices);
    }
};