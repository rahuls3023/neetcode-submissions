class Solution {
public:

    int tabulation(vector<int>&coins,int amount){
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));

        // dp[index][amount] = minimum number of coins required to make 'amount'
        // using coins from index to n-1 (each coin can be used unlimited times).

        // Base case:
        // Amount 0 can always be formed using 0 coins, regardless of the current index.
        for (int index = 0; index <= n; index++) {
            dp[index][0] = 0;
        }

        for(int index=n-1;index>=0;index--){
            for(int currAmount=0;currAmount<=amount;currAmount++){
                // Initialize as impossible because taking the current coin may not be valid
                // (when coins[index] > amount). Initializing with 0 would incorrectly mean
                // 0 coins are enough even when this choice cannot be taken.
                
                int take = 1e9;
                if(coins[index]<=currAmount){
                    take=1+dp[index][currAmount-coins[index]];
                }

                int not_take=dp[index+1][currAmount];

                dp[index][currAmount]=min(take,not_take);
            }
        }
        return dp[0][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        
       int ans= tabulation(coins,amount);

       if(ans==1e9) return -1;
       else return ans;
    }
};