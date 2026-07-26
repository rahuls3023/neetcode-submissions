class Solution {
public:
    int memoisation(int index,int amount,vector<int>&coins,vector<vector<int>>&dp){

        if(amount==0){
            return 1;
        }

        if(index>=coins.size()){
            return 0;
        }

        // dp[index][amount] = number of unique combinations to make the remaining
        // amount using coins from index to n-1 (each coin can be used unlimited times).

        if(dp[index][amount]!=-1) return dp[index][amount];

        int take=0;
        if(coins[index]<=amount){
            take+=memoisation(index,amount-coins[index],coins,dp);
        }
        int not_take=memoisation(index+1,amount,coins,dp);

        return dp[index][amount]= (take+not_take);
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return memoisation(0,amount,coins,dp);
    }
};