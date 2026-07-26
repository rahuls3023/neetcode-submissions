class Solution {
public:
    int tabulation(string &text1,string &text2){
        int m=text1.size();
        int n=text2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        // dp[i][j] = length of the longest common subsequence
        // between text1 starting from index i and text2 starting from index j

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                if(text1[i]==text2[j]){
                     dp[i][j]= 1+dp[i+1][j+1];
                }else{
                    //we have two choices
                    //either we can match for ith character by increasing j or we can match jth character by increasin i.
                     dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return tabulation(text1,text2);
    }
};