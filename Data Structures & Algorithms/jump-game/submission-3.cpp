class Solution {
public://greedy-> O(n)
    bool canJump(vector<int>& nums) {
        int maxReacheableIndex=0;

        for(int i=0;i<nums.size();i++){
            int currentMaximumReacheable=nums[i]+i;

            if(i>maxReacheableIndex){
                //max reacheable hi ye index tha iske aage kese nikl gye
                return false;
            }

            if(maxReacheableIndex<currentMaximumReacheable){
               maxReacheableIndex=currentMaximumReacheable;
            }
        }
       return true;
    }
};