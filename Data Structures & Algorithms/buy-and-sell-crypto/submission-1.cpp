class Solution {
public://optimal approach
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int minPrice = prices[0];
        int maximumProfit = 0;

        for(int i=1;i<n;i++){
            // Sell stock at current price
            int currentProfit = prices[i] - minPrice;

            maximumProfit=max(maximumProfit,currentProfit);

            // Update minimum buying price
            minPrice = min(minPrice, prices[i]);
        }
        return maximumProfit;
    }
};
