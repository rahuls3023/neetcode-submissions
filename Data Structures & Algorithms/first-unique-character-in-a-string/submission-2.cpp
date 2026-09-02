class Solution {
public://approach-2> using hashmap
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }

        //first unique character
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};