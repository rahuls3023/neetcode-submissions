class Solution {
public:
    void solve(int index,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }

        if(index>=nums.size() || target<0) return;

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;//skip duplicate elements;

            curr.push_back(nums[i]);//PUSH

            solve(i+1,nums,target-nums[i],ans,curr);

            curr.pop_back();//BACKTRACK
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<vector<int>>ans;
        vector<int>curr;

        solve(0,candidates,target,ans,curr);

        return ans;
    }
};