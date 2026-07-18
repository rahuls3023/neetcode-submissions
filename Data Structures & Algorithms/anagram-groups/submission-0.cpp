class Solution {
public:// approach-1> sorting and hashmap
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            //make a copy of original string
            string toSort=strs[i];

            sort(toSort.begin(),toSort.end());

            mp[toSort].push_back(strs[i]);
        }

        vector<vector<string>>ans;

        for(auto it:mp){
            auto strings=it.second;

            ans.push_back(strings);
        }
        return ans;
    }
};
