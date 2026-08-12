class Solution {
public:
    bool memoisation(string &s, string &p,int i,int j,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size()){
            return true;
        }

        if(i!=s.size() && j==p.size()) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        // check current character match
        bool currMatch=(i<s.length()) && (p[j]=='.' || s[i]==p[j]);

        //if next character is'*'
        if(j+1<p.length() && p[j+1]=='*'){
            //char* -> mtlb previous character 0 or more times aa skta h

             // choice 1 -> use char* 0 times, so skip both char and '*'
            // choice 2 -> use current char once and stay at same pattern index
            return  dp[i][j]= memoisation(s,p,i,j+2,dp) ||  (currMatch && memoisation(s, p, i + 1, j, dp));
        }

         // normal match without '*'
        if(currMatch==true) {
            return dp[i][j]= memoisation(s, p, i + 1, j + 1,dp);
        }
        return dp[i][j] =false;
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memoisation(s,p,0,0,dp);
    }
};