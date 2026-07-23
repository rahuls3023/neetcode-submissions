class Solution {
public:
    void solve(int index,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
            
            //pick current element and explore
            temp.push_back(nums[index]);
            solve(index+1,nums,ans,temp);

            //not-take and explore
            temp.pop_back();
              // Skip all duplicate elements before taking the not-pick branch
            while(index + 1 < nums.size() && nums[index] == nums[index + 1]) {
                index++;
            }

            solve(index+1,nums,ans,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans,temp);
        return ans;
    }
};