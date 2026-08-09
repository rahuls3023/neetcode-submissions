class Solution {
public:
    int recursion(int index,int canBuy,vector<int>&prices){
        if(index>=prices.size()) return 0;

        if(canBuy==1){
            //we can buy today if we want
            int buyToday=-prices[index]+recursion(index+1,0,prices);//we pay price thats why -
            int skipBuyToday=recursion(index+1,1,prices);
            return max(buyToday,skipBuyToday);
        }
        else{
            //we cannnot buy
            //we already have some stock
            // try selling it
            int sellToday=prices[index]+recursion(index+2,1,prices);
            int skipsellToday=recursion(index+1,0,prices);

            return max(sellToday,skipsellToday);
        }
    }
    int maxProfit(vector<int>& prices) {
        return recursion(0,1,prices);
    }
};