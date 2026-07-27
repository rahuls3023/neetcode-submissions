class Solution {
public:
    int tabulation(string &word1,string &word2){
        int m=word1.size();
        int n=word2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)); 

        // dp[i][j] = minimum operations required to convert word1 from index i to end into
        // word2 from index j to end  

        //word1 finishes early
        //insert word2 char in word1
        for(int j=0;j<=n;j++){
            dp[m][j]=n-j;
        }


        //word2 finishes early
        //delete from word 1
        for(int j=0;j<=m;j++){
            dp[j][n]=m-j;
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]= dp[i+1][j+1];
                }
                else{
                    //we have 3 cases
                    
                    //agar word1 me character replace from from word2
                    int replace=1+dp[i+1][j+1];

                    //agar word1 ka character delete krdia
                    int deleteIt=1+dp[i+1][j];
                    
                    //agar word1 me insert krdia current character from word 2
                    //because abhi original jo match krna tha word1 ka char wo match hona bcha h
                    int insert=1+dp[i][j+1]; 

                    dp[i][j]= min({replace,deleteIt,insert});
                }
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        return tabulation(word1,word2);
    }
};