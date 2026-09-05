class Solution {
public://approach-2>  determine kro konsi direction h increasing ya decreasing
    bool isMonotonic(vector<int>& nums) {
        int i=1;

        //skip equal elements
        while(i<nums.size() && nums[i]==nums[i-1]) i++;

        //all elemnts are equal
        if(i==nums.size())return true;

        //determine direction

        bool increasing=nums[i]>nums[i-1];//agar current bda h to iska mtlb increasing h

        //check remaining elemnts
        for(;i<nums.size();i++){
            if(increasing==true && nums[i]<nums[i-1]) return false;//violating increasing property

            if(increasing==false && nums[i]>nums[i-1]) return false;//decreasing ki property violate krdia
        }
        return true;
    }
};