class Solution {
public://brute force
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            int currentWindowMaximum=0;
            for(int j=i;j<n;j++){
                currentWindowMaximum+=nums[j];

                if(maxi<currentWindowMaximum){
                    maxi=currentWindowMaximum;
                }
            }
        }
        return maxi;
    }
};