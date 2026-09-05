class Solution {
public://approach-1> check both increasing and decreasing
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                increasing=false;//array increasing nhi h
            }
             if(nums[i] > nums[i - 1])//array decreasing nhi h
                decreasing = false;
        }
        return increasing || decreasing;
    }
};