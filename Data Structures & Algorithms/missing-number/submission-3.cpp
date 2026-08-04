class Solution {
public://approach-3> using xor using 1 loop
    int missingNumber(vector<int>& nums) {
        //as we need xor from [0--->n]
        //we will start with n
        int n=nums.size();

        int ans=n;
        
        for(int i=0;i<n;i++){
            ans^=i;
            ans^=nums[i];
        }
        return ans;
    }
};
