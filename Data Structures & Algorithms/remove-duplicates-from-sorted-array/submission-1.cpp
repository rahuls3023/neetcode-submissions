class Solution {
public://approach-2> without extra space
    int removeDuplicates(vector<int>& nums) {
        int k=1;//index where we have to put elements that are not duplicate to previous
        

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};