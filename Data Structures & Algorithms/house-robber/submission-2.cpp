class Solution {
public:
    int tabulation(vector<int>&nums){
        int n=nums.size();
        vector<int>dp(n+2,0);

        for(int index=n-1;index>=0;index--){
            //agar chori kri
            int steal=0;
            steal+=nums[index]+dp[index+2];

            //agar isko skip krdia
            int not_steal=0;
            not_steal+=dp[index+1];

            dp[index]=max(steal,not_steal);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        return tabulation(nums);
    }
};