class Solution {
public:
    bool tabulation(string &s1,string &s2,string &s3){
        int m=s1.size();
        int n=s2.size();
        int o=s3.size();

        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(o+1,0)));

        dp[m][n][o]=1;//base case

        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                //willl start from o-1 bcz o ke lie base case likh chuke h hum base case me o ka end pe hona necessary tha uske baad check horha tha true ya false.
                for(int k=o-1;k>=0;k--){
                    bool ans=false;

                    //take s1 character
                    if(i<s1.size() && s1[i]==s3[k]){
                        ans=ans | dp[i+1][j][k+1];
                    }

                    //take s2 character
                    if(j<s2.size() && s2[j]==s3[k]){
                        ans = ans | dp[i][j+1][k+1];
                    }

                    dp[i][j][k]= ans;
                    }
            }
        }
        return dp[0][0][0];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;

        return tabulation(s1,s2,s3);
    }
};