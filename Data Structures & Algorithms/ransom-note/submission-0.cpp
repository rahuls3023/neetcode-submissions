class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;

        for(auto it:ransomNote){
            mp[it]++;
        }

        for(int i=0;i<magazine.size();i++){
            if(mp[magazine[i]]!=0){
                mp[magazine[i]]--;
            }
        }

        for(auto it:mp){
            if(it.second>0){
                return false;
            }
        }
        return true;
    }
};