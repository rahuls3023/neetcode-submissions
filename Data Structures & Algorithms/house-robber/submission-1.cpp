class Solution {
public:
    int memoisation(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        //agar chori kri
        int steal=0;
        steal+=nums[index]+memoisation(index+2,nums,dp);

        //agar isko skip krdia
        int not_steal=0;
        not_steal+=memoisation(index+1,nums,dp);

        return dp[index]= max(steal,not_steal);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+2,-1);
        return memoisation(0,nums,dp);
    }
};