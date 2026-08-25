class Solution {
public://brute force
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        int num=1;

        while(true){
            if(mp.find(num)==mp.end()) return num;
            num++;
        }
    }
};