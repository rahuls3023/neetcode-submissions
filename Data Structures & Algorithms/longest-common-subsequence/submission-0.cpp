class Solution {
public:
    int memoisation(int i,int j,string text1,string text2,vector<vector<int>>&dp){

        if(i<0 || i>=text1.size() || j<0 || j>=text2.size()) return 0;

        // dp[i][j] = length of the longest common subsequence
        // between text1 starting from index i and text2 starting from index j.

        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]){
            return dp[i][j]= 1+memoisation(i+1,j+1,text1,text2,dp);
        }else{
            //we have two choices
            //either we can match for ith character by increasing j or we can match jth character by increasin i.
            return dp[i][j]= max(memoisation(i+1,j,text1,text2,dp),memoisation(i,j+1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memoisation(0,0,text1,text2,dp);
    }
};