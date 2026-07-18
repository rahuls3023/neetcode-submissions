class Solution {
public://approach 2 -> hashmap
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];

            if(mp.find(need)!=mp.end()){
                //milgya
                return {mp[need],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
