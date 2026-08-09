class Solution {
public:
    int recursion(int index,vector<int>&nums){
        if(index>=nums.size()) return 0;

        //agar chori kri
        int steal=0;
        steal+=nums[index]+recursion(index+2,nums);

        //agar isko skip krdia
        int not_steal=0;
        not_steal+=recursion(index+1,nums);

        return max(steal,not_steal);
    }
    int rob(vector<int>& nums) {
        return recursion(0,nums);
    }
};