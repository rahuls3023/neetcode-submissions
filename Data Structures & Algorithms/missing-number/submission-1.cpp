class Solution {
public://approach-2> using sum approach
    int missingNumber(vector<int>& nums) {
        int givenSum=0;

        for(int i=0;i<nums.size();i++){
            givenSum+=nums[i];
        }

        int actualsum=0;

        for(int i=0;i<=nums.size();i++){
            actualsum+=i;
        }

        return actualsum-givenSum;
    }
};
