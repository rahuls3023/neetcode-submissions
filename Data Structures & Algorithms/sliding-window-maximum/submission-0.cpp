class Solution {
public://brute force
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<=n-k;i++){
            int windowMaximum=nums[i];
            for(int j=i;j<i+k;j++){
                windowMaximum=max(windowMaximum,nums[j]);
            }
            ans.push_back(windowMaximum);
        }
        return ans;
    }
};
