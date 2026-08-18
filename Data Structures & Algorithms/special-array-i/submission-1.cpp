class Solution {
public://check adjacent element parity
    bool isArraySpecial(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2 == nums[i-1]%2){
                return false;
            }
        }
        return true;
    }
};