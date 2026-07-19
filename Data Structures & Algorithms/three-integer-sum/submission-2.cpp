class Solution {
public://optimal approach-> using 3 variables
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        //sort the array first
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){

            //duplicates handle
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int left=i+1;
            int right=n-1;

            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];

                if(sum==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                    //skip  left duplicates value after finding every triplet
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }

                    //skip right duplicates after finding every triplet
                    while(left<right && nums[right]==nums[right+1]){
                        right--;
                    }
                    
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};
