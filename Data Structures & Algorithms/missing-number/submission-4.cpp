class Solution {
public://sorting approach
    int missingNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));

        //now just check if nums[i]==i or not
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }

        return nums.size();
    }
};