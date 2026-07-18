class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq;

        if(s.length()!=t.length()) return false;

        for(auto it:s){
            freq[it]++;
        }

        for(auto it:t){
            freq[it]--;
        }

        for(auto it:freq){
            if(it.second>0) return false;
        }
        return true;
    }
};
