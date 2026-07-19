class Solution {
public://brute force-> calculate all substrings
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLength=0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                //duplicate found
                if (mp[s[j]] == 1){
                    break;
                }
                 mp[s[j]]++;
                 maxLength=max(maxLength,j-i+1);
            }
        }
        return maxLength;
    }
};
