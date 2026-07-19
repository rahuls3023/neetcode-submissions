class Solution {
public://brute force-> extra string
    bool isPalindrome(string s) {
        int n=s.size();
        string ans="";

        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                ans+=tolower(s[i]);
            }
        }

        //now check for palindrome
        int i=0;
        int j=ans.size()-1;

        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
