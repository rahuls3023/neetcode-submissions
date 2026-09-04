class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(26,0);

        for(auto it:ransomNote){
            freq[it-'a']++;
        }

        for(int i=0;i<magazine.size();i++){
            if( freq[magazine[i]-'a']>0){
                 freq[magazine[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(freq[i]>0){
                return false;
            }
        }
        return true;
    }
};