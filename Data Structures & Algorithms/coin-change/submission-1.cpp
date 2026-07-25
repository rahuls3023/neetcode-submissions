class Solution {
public:
    int memoisation(int index,vector<int>&coins,int amount,vector<vector<int>>&dp){
        //make call for amount first as whenever amount becomes 0 we need to return 0 first rather than 1e9
        if(amount==0) return 0;

        if(index>=coins.size()) return 1e9;

        if(dp[index][amount]!=-1) return dp[index][amount];

        // Initialize as impossible because taking the current coin may not be valid
        // (when coins[index] > amount). Initializing with 0 would incorrectly mean
        // 0 coins are enough even when this choice cannot be taken.
        int take = 1e9;
        if(coins[index]<=amount){
            take=1+memoisation(index,coins,amount-coins[index],dp);
        }

        int not_take=memoisation(index+1,coins,amount,dp);

        return dp[index][amount]=min(take,not_take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
       int ans= memoisation(0,coins,amount,dp);

       if(ans==1e9) return -1;
       else return ans;
    }
};