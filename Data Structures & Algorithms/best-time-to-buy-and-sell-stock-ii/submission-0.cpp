class Solution {
public:
    int recursion(int index,int canBuy,vector<int>&prices){
        if(index>=prices.size()) return 0;

        //means we can buy on this index
        //we can either buy today or skip buying today
        if(canBuy==1){
            int buytoday=-prices[index]+recursion(index+1,0,prices);

            int skipBuyToday=recursion(index+1,1,prices);

            return max(buytoday,skipBuyToday);
        }
        else{
            //means we already have some stocks, we need to sell it
            //we can either sell today or skip sell today

            int sellToday=prices[index]+recursion(index+1,1,prices);

            int skipSellToday=recursion(index+1,0,prices);

            return max(sellToday,skipSellToday);
        }
    }
    int maxProfit(vector<int>& prices) {
        return recursion(0,1,prices);
    }
};