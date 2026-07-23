class Solution {
public://recursion
    void solve(int index,vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr){
        ans.push_back(curr);

        for(int j=index;j<nums.size();j++){
            curr.push_back(nums[j]);

            solve(j+1,nums,ans,curr);

            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,nums,ans,curr);
        return ans;
    }
};
