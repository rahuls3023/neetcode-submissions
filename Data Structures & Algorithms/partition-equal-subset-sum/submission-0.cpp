class Solution {
public:
    bool recursion(int index,vector<int>&nums,int target){
        if(target==0) return true;

        if(index>=nums.size()){
            if(target==0) return true;
            else return false;
        }

        bool include=false;
        if(nums[index]<=target){
            include=recursion(index+1,nums,target-nums[index]);
        }

        bool exclude=recursion(index+1,nums,target);

        return (include || exclude);
    }
    bool canPartition(vector<int>& nums) {
       int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum%2!=0) return false;//cant be partitioned

        int target=totalSum/2;

        return recursion(0,nums,target);
    }
};