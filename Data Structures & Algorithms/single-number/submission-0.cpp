class Solution {
public://brute force using extra space
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            int num=it.first;
            int freq=it.second;

            if(freq==1) return num;
        }
        return -1;
    }
};
