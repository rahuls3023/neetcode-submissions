class Solution {
public://recursion
    bool isPalindrome(int i,int j,string s){
        //base case
        if(i>=j) return true;

        if(s[i]==s[j]){
            return isPalindrome(i+1,j-1,s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLen=0;
        int startIndex=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        startIndex=i;
                    }
                }
            }
        }
        return s.substr(startIndex,maxLen);
    }
};