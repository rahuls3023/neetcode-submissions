class Solution {
public://recursion type-2
    int recursion(int index,vector<int>&nums,int target){
        if(index>=nums.size()){
            if(target==0){
                return 1;
            }
            else return 0;
        }

        //we have two choices for every index
        //we can either use '+' symbol or we can either use '-' symbol

        int plus=recursion(index+1,nums,target+nums[index]);
        int subtract=recursion(index+1,nums,target-nums[index]);

        return plus+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(0,nums,target);
    }
};