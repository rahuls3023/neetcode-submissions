class Solution {
public:
    int recursion(int index,vector<int>&nums,int lastIndex){
        if(index>=nums.size()) return 0;

        int current=nums[index];

        int include=0;
        if(lastIndex==-1 || current>nums[lastIndex]){
            include=1+recursion(index+1,nums,index);
        }

        int exclude=recursion(index+1,nums,lastIndex);

        return max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recursion(0,nums,-1);
    }
};