class Solution {
public://better approach-> sorting and compare
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) return nums[i];
        }
        return -1;
    }
};
