class Solution {
public://brute force
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int currentRange=0;

            for(int j=i;j<n;j++){
                if(nums[j]==1){
                    currentRange++;
                    maxi=max(maxi,currentRange);
                }
                else break;
            }
        }
        return maxi;
    }
};