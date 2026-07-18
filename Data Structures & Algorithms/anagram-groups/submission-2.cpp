class Solution {
public://approach-2> using frequency array and making string from it.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        //create freq array for every string
        for(auto str:strs){
            vector<int>freq(26,0);

            for(auto it:str){
                freq[it-'a']++;
            }
                //convert frequency array into unique string key

                string key="";

                for(int i=0;i<26;i++){
                    key+=to_string(freq[i])+"#";
                }
                mp[key].push_back(str);
            }
            vector<vector<string>>ans;
            for(auto it:mp){
                ans.push_back(it.second);
            }
            return ans;
    }
};
