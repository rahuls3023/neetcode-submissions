class Solution {
public://optimal approach-1> two pass method
    void moveZeroes(vector<int>& nums) {
        int k=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[k]=nums[i];
                k++;
            }
        }

        //now put 0 for leftover k indexes
         while(k<nums.size()){
            nums[k]=0;
            k++;
        }
        
    }
};