class Solution {
public:
    int tabulation(int start, int end, vector<int>& nums) {
        int n = nums.size();

        // dp[index] = maximum money that can be robbed
        // starting from 'index' till 'end'
        vector<int> dp(n + 2, 0);

        for (int index = end; index >= start; index--) {

            // Rob the current house, so the adjacent house cannot be robbed
            int steal = nums[index] + dp[index + 2];

            // Skip the current house and move to the next house
            int skip = dp[index + 1];

            dp[index] = max(steal, skip);
        }

        // We started solving from 'start', so our answer is stored here
        return dp[start];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // Case 1: Exclude the last house (consider houses 0 to n-2)
        int excludeLast = tabulation(0, n - 2, nums);

        // Case 2: Exclude the first house (consider houses 1 to n-1)
        int excludeFirst = tabulation(1, n - 1, nums);

        return max(excludeLast, excludeFirst);
    }
};