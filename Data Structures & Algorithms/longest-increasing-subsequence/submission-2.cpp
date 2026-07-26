class Solution {
public:
    int tabulation(vector<int>&nums){
        int n=nums.size();
         // dp[index][lastIndex + 1] =
        // length of LIS starting from 'index',
        // where the previously selected element is at 'lastIndex'
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int index=n-1;index>=0;index--){
            for(int lastIndex=index-1;lastIndex>=-1;lastIndex--){
                int include=0;
                if(lastIndex==-1 || nums[index]>nums[lastIndex]){
                    include=1+dp[index+1][index+1];
                }

                int exclude=dp[index+1][lastIndex+1];

                dp[index][lastIndex+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {   
        return tabulation(nums);
    }
};