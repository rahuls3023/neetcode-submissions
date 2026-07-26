class Solution {
public:

    int tabulation(vector<int>&nums,int target){
        int n=nums.size();

        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        //dp[index][target] = Can we make the remaining target sum using elements from index to n-1?

        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        for(int index=n-1;index>=0;index--){
            for(int currAmount=0;currAmount<=target;currAmount++){
                bool include=false;
                if(nums[index]<=currAmount){
                    include=dp[index+1][currAmount-nums[index]];
                }

                bool exclude=dp[index+1][currAmount];

                dp[index][currAmount]=include || exclude;
            }
        }
        return dp[0][target];
    }
    bool canPartition(vector<int>& nums) {
       int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum%2!=0) return false;//cant be partitioned

        int target=totalSum/2;

        return tabulation(nums,target);
    }
};