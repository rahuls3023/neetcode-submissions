class Solution {
public://approach-1> using map and custom comparator
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        
        // map -> vector of pairs
        vector<pair<int,int>> v;

        for(auto it : mp) {
            v.push_back({it.first, it.second});
        }

        //sort the v vector according to freq
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){

            //frequency increasing
            if(a.second!=b.second){
                return a.second<b.second;
            }
            //same frequency-> decreasing value
            return a.first>b.first;
        });

        vector<int>ans;

         for(auto it : v) {

            int value = it.first;
            int frequency = it.second;

            while(frequency--) {
                ans.push_back(value);
            }
        }

        return ans;
    }
};