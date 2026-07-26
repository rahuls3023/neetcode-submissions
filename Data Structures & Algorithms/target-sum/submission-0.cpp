class Solution {
public://recursion type-1
    int recursion(int index,vector<int>&nums,int currSum,int target){
        if(index>=nums.size()){
            if(currSum==target){
                return 1;
            }
            else return 0;
        }

        //we have two choices for every index
        //we can either use '+' symbol or we can either use '-' symbol

        int plus=recursion(index+1,nums,currSum+nums[index],target);
        int subtract=recursion(index+1,nums,currSum-nums[index],target);

        return plus+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(0,nums,0,target);
    }
};