class Solution {
public:
    int memoisation(int index,vector<int>&nums,int lastIndex, vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;

        if(dp[index][lastIndex+1]!=-1) return dp[index][lastIndex+1];

        int current=nums[index];

        int include=0;
        if(lastIndex==-1 || current>nums[lastIndex]){
            include=1+memoisation(index+1,nums,index,dp);
        }

        int exclude=memoisation(index+1,nums,lastIndex,dp);

        return dp[index][lastIndex+1]=max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memoisation(0,nums,-1,dp);
    }
};