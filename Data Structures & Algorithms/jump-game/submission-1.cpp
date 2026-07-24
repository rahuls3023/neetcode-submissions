class Solution {
public://recursion-> dp(top-down)
    bool memoisation(int index,vector<int>&nums,vector<int>&dp){
        if(index==nums.size()-1) return true;//reached last index
        if(index>=nums.size()) return false;
        if(nums[index]==0) return false;

        if(dp[index]!=-1) return dp[index];

        bool ans=false;
        //we can jump between 1 step to that index value.
        for(int jump=1;jump<=nums[index];jump++){
            if(memoisation(jump+index,nums,dp)==true)
            return dp[index]= true;
        }
        return dp[index]= ans;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return memoisation(0,nums,dp);
    }
};