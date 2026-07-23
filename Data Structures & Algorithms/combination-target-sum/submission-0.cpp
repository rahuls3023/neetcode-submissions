class Solution {
public://recursion+backtracking
    void solve(int index,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }

        if(index>=nums.size() || target<0) return;

        //pick
        curr.push_back(nums[index]);
        solve(index,nums,target-nums[index],ans,curr);
        curr.pop_back();


        //not-pick
        solve(index+1,nums,target,ans,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;

        solve(0,candidates,target,ans,curr);
        return ans;
    }
};