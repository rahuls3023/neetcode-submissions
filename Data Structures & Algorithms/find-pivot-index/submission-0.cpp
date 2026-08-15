class Solution {
public://optimal->O(N)
    int pivotIndex(vector<int>& nums) {
        int totalSum=0;

        //total sum nikalo
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }

        int leftSum=0;

        for(int i=0;i<nums.size();i++){
             //current index ko exclude krke right side ka sum
            int rightSum=totalSum-leftSum-nums[i];

            if(leftSum==rightSum){
                return i;//leftmost pivot index
            }

             //current element ab next index ke lie left side me aa jayega
            leftSum+=nums[i];
        }
        return -1;
    }
};