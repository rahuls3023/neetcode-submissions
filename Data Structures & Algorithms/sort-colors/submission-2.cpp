class Solution {
public://approach-3>DUTCH NATIONAL FLAG
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=0;
        int k=nums.size()-1;

        while(j<=k){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==2){
                swap(nums[k],nums[j]);
                k--;
            }
            else{
                j++;
            }
        }
    }
};