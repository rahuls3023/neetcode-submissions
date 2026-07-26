class Solution {
public:
    bool memoisation(int index,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0) return true;

        if(index>=nums.size()){
            if(target==0) return true;
            else return false;
        }

        if(dp[index][target]!=-1) return dp[index][target];

        bool include=false;
        if(nums[index]<=target){
            include=memoisation(index+1,nums,target-nums[index],dp);
        }

        bool exclude=memoisation(index+1,nums,target,dp);

        return dp[index][target]=(include || exclude);
    }
    bool canPartition(vector<int>& nums) {
       int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum%2!=0) return false;//cant be partitioned

        int target=totalSum/2;

        int n=nums.size();

        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        return memoisation(0,nums,target,dp);
    }
};