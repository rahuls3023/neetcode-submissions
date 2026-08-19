class Solution {
public://approach-1>linear search
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return 0;

        //first elemnt peak
        if(nums[0]>nums[1]) return 0;

        //last element peak
        if(nums[n-1]>nums[n-2]) return n-1;

        int ans=-1;

        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1]){
                ans=i;
            }
        }
        return ans;
    }
};