class Solution {
public://recursion
    bool solve(int index,vector<int>&nums){
        if(index==nums.size()-1) return true;//reached last index
        if(nums[index]==0) return false;
        if(index>=nums.size()) return false;

        bool ans=false;
        //we can jump between 1 to that nums value
        for(int jump=1;jump<=nums[index];jump++){
            ans=ans || solve(jump+index,nums);
        }
        return ans;
    }
    bool canJump(vector<int>& nums) {
        return solve(0,nums);
    }
};