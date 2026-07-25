class Solution {
public://optimal-> expand around center
    void expandAroundCenter(string &s,int left,int right,int &maxLen,int &startIndex){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }

          int len=right-left-1;//-1 kyuki left palindrome se ek pehle khada hoga.

        if(len>maxLen){
            maxLen=len;
            startIndex=left+1;//+1 kyuki jab loop khtm hua hoga while to left, palindrome se ek piche hoga
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();

        int maxLen=1;
        int startIndex=0;

        for(int i=0;i<n;i++){
            //agar even length hai

            expandAroundCenter(s,i,i+1,maxLen,startIndex);

            //agar odd length

            expandAroundCenter(s,i,i,maxLen,startIndex);
        }

        return s.substr(startIndex,maxLen);
    }
};