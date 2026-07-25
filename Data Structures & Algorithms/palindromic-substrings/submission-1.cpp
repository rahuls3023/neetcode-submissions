class Solution {
public://memoisation
    bool isPalindrome(int left,int right,string &s,vector<vector<int>>&dp){

        if(left>=right) return true;

        if(dp[left][right]!=-1) return dp[left][right];

        if(s[left]==s[right]){
            return dp[left][right]=isPalindrome(left+1,right-1,s,dp);
        }

        return dp[left][right]= false;

    }
    int countSubstrings(string s) {
        int n=s.size();

        int totalPalindrome=0;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp)){
                    totalPalindrome+=1;
                }
            }
        }
        return totalPalindrome;
    }
};