class Solution {
public://approach-2>one pass -> 2 pointer-> swap method
    void moveZeroes(vector<int>& nums) {
        int k=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[k]);
                k++;
            }
        }
    }
};