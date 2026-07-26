class Solution {
public:
    int tabulation(int amount,vector<int>&coins){
        int n=coins.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(amount+1,0));

        // dp[index][amount] = number of unique combinations to make the remaining
        // amount using coins from index to n-1 (each coin can be used unlimited times).

        // Amount 0 -> 1 way (choose nothing)
        // No coins left & amount > 0 -> 0 ways
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int index=n-1;index>=0;index--){
            for(int currAmount=0;currAmount<=amount;currAmount++){
                unsigned long long take=0;
                if(coins[index]<=currAmount){
                    take+=dp[index][currAmount-coins[index]];
                }
                unsigned long long not_take=dp[index+1][currAmount];

                dp[index][currAmount]=take+not_take;
            }
        }
        return  (int)dp[0][amount];
    }
    int change(int amount, vector<int>& coins) {
        
        return tabulation(amount,coins);
    }
};