class Solution {
public://optimal approach-> tortoise and hare method.
    int findDuplicate(vector<int>& nums) {
        
        //step-1> detect cycle
        //fast==slow hoti thi condition but shuru me fast aur slow ke same se shuru kr dege to while loop kbhi chalega hi nhi, isliye fast ko 1 step aage rkho than slow.

        int slow=nums[0];
        int fast=nums[0];

        slow=nums[slow];
        fast=nums[nums[fast]];//double move

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        //it breaks when we detect a cycle
        //now we will find the starting of cycle

        //start slow from starting
        slow=nums[0];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};