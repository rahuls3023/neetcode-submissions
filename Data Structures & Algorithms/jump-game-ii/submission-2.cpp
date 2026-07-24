class Solution {
public://greedy
    int jump(vector<int>& nums) {
        int maxDistance=0;
        int currentDistance=0;//maximum we can reach from current range
        int jumps=0;

        for(int i=0;i<nums.size()-1;i++){//exclude the last element
            maxDistance=max(nums[i]+i,maxDistance);//maxDistance we can reach

            if(i==currentDistance){
                //we need to make 1 jump as we have reached the last index of current range
                jumps++;

                currentDistance=maxDistance;
            }
        }
        return jumps;
    }
};