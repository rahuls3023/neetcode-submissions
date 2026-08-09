class Solution {
public:
    int recursion(int index,vector<int>&nums){
        int n=nums.size();

        if(index>=n-1) return 0;//reached destination, no more steps needed

        int ans=1e9;

        for(int jump=1;jump<=nums[index];jump++){
            ans=min(ans,1+recursion(index+jump,nums));//1+ for every step
        }
        return ans;
    }
    int jump(vector<int>& nums) {
        return recursion(0,nums);
    }
};