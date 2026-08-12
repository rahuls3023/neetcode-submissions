class Solution {
public:
    bool memoisation(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        //base case
        if(k==s3.size()){
            if(i==s1.size() && j==s2.size()) return true;
            else return false;
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        //choose or not choose
        bool ans=false;

        //take s1 character
        if(i<s1.size() && s1[i]==s3[k]){
            ans=ans | memoisation(s1,s2,s3,i+1,j,k+1,dp);
        }

        //take s2 character
        if(j<s2.size() && s2[j]==s3[k]){
            ans = ans | memoisation(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j][k]= ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;

        int m=s1.size();
        int n=s2.size();
        int o=s3.size();

        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(o+1,-1)));

        return memoisation(s1,s2,s3,0,0,0,dp);
    }
};