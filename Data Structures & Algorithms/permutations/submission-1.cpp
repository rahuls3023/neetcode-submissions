class Solution {
public://approach-2->swapping

    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){// Try every element from idx to end at the current position
            swap(nums[i],nums[idx]);
            solve(idx+1,nums,ans);// Recursively fix the next position
            swap(nums[i],nums[idx]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }
};