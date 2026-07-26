class Solution {
public:// memoisation for recursion type-2
    int recursion(int index,vector<int>&nums,int target,vector<vector<int>>&dp,int totalSum){

         //  IMPORTANT BOUND CHECK
       // range define kiya → to uske bahar jaane se pehle guard laga
       //Agar remaining target itna bada/chhota hai ki jitne numbers bache hain unse kabhi bhi achieve nahi ho sakta, to 0 ways.
        if(target > totalSum || target < -totalSum)
        return 0;

        if(index>=nums.size()){
            if(target==0){
                return 1;
            }
            else return 0;
        }

       //dp[index][target]= Number of ways to achieve the remaining target using elements from index to n-1.

        if(dp[index][target+totalSum]!=-1) return dp[index][target+totalSum];//to avoid negative index acess

        //we have two choices for every index
        //we can either use '+' symbol or we can either use '-' symbol

        int plus=recursion(index+1,nums,target+nums[index],dp,totalSum);
        int subtract=recursion(index+1,nums,target-nums[index],dp,totalSum);

        return dp[index][target+totalSum]=plus+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>>dp(n+1,vector<int>(2*totalSum+1,-1));

        return recursion(0,nums,target,dp,totalSum);
    }
};