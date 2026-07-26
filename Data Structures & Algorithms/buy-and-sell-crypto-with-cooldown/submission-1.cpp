class Solution {
public:
    int memoisation(int index,int canBuy,vector<int>&prices,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;

        //dp[index][canBuy]=maximum profit we can earn
        // starting from day 'index' till the last day.
        //canBuy can be 0 or 1

        if(dp[index][canBuy]!=-1) return dp[index][canBuy];

        if(canBuy==1){
            //we can buy today if we want
            int buyToday=-prices[index]+memoisation(index+1,0,prices,dp);//we pay price thats why -
            int skipBuyToday=memoisation(index+1,1,prices,dp);
            return  dp[index][canBuy]= max(buyToday,skipBuyToday);
        }
        else{
            //we cannnot buy
            //we already have some stock
            // try selling it
            int sellToday=prices[index]+memoisation(index+2,1,prices,dp);
            int skipsellToday=memoisation(index+1,0,prices,dp);

            return  dp[index][canBuy]= max(sellToday,skipsellToday);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return memoisation(0,1,prices,dp);
    }
};