class Solution {
public://by recursion
    void solve(vector<int>&prices,int index,int &minimumPrice,int &maxProfit){
        if(index>=prices.size()) return;

        if(prices[index]<minimumPrice) minimumPrice=prices[index];

        int profit=prices[index]-minimumPrice;

        maxProfit=max(maxProfit,profit);

        solve(prices,index+1,minimumPrice,maxProfit);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minimumPrice=prices[0];
        int maxProfit=0;

        solve(prices,1,minimumPrice,maxProfit);
        return maxProfit;
    }
};
