class Solution {
public://optimal-2> pointer
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;

        while(i<s.size() && j<t.size()){
           if(s[i]==t[j]){
            i++;
           }
           j++;
        }

        if(i==s.size()) return true;
        else return false;
    }
};