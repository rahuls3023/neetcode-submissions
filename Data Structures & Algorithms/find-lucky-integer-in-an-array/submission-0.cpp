class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(auto it:arr){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.first==it.second) return it.first;
        }
        return -1;
    }
};