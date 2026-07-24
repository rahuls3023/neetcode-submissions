class Solution {
public:
    int memoisation(int index,vector<int>&nums,vector<int>&dp){
        int n=nums.size();

        if(index>=n-1) return 0;//reached n-1, no more steps needed

        if(dp[index]!=-1) return dp[index];

        int ans=1e9;

        for(int jump=1;jump<=nums[index];jump++){
            ans=min(ans,1+memoisation(index+jump,nums,dp));//1+ for every step
        }
        return dp[index]= ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return memoisation(0,nums,dp);
    }
};