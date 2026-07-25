class Solution {
public://memoisation
    bool isPalindrome(int i,int j,string &s,vector<vector<int>>&dp){
        //base case
        if(i>=j) return 1;//1-> true

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]= isPalindrome(i+1,j-1,s,dp);
        }
        return dp[i][j]= 0;//0-> false
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLen=0;
        int startIndex=0;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp)){
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