class Solution {
public://approach-3> using xor using 2 loop
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xorvalue=0;

        for(int i=0;i<nums.size();i++){
            xorvalue^=nums[i];
        }

        for(int i=0;i<=n;i++){
            xorvalue^=i;
        }
        return xorvalue;
    }
};
