class Solution {
public:
    int recursion(int index, vector<int>& coins, int amount) {

        // Base case:
        // If amount becomes 0, no more coins are needed.
        // This check is done first because recursion(index = n, amount = 0)
        // should return 0 (successful), not impossible.
        if (amount == 0) return 0;

        // No coins left, but amount is still not 0 -> impossible to form amount
        if (index >= coins.size()) return 1e9;

        // Initialize as impossible because taking the current coin may not be valid
        // (when coins[index] > amount). Initializing with 0 would incorrectly mean
        // 0 coins are enough even when this choice cannot be taken.
        int take = 1e9;
        if (coins[index] <= amount) {
            take = 1 + recursion(index, coins, amount - coins[index]);
        }

        // Option 2: Skip current coin and move to next coin
        int not_take = recursion(index + 1, coins, amount);

        // Return minimum coins required
        return min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {

        int ans = recursion(0, coins, amount);

        // If amount cannot be formed, return -1
        if (ans == 1e9) return -1;

        return ans;
    }
};