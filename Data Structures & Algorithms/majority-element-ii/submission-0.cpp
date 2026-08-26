class Solution {
public://approach-1> map
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;

        int n=nums.size();

        int limit=n/3;

        vector<int>ans;

        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.second>limit){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};