class Solution {
public:
    int tabulation(vector<int>&prices){
         int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

         //dp[index][canBuy]=maximum profit we can earn
        // starting from day 'index' till the last day.
        //canBuy can be 0 or 1

        for(int index=n-1;index>=0;index--){
            for(int canBuy=1;canBuy>=0;canBuy--){
                if(canBuy==1){
                //we can buy today if we want
                int buyToday=-prices[index]+dp[index+1][0];//we pay price thats why (-)

                int skipBuyToday=dp[index+1][1];

                dp[index][canBuy]= max(buyToday,skipBuyToday);
                }
                else{
                    //we cannnot buy
                    //we already have some stock
                    // try selling it
                    int sellToday=prices[index]+dp[index+2][1];
                    int skipsellToday=dp[index+1][0];

                    dp[index][canBuy]= max(sellToday,skipsellToday);
                }
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
       
        return tabulation(prices);
    }
};