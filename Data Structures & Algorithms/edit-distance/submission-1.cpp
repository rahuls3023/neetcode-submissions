class Solution {
public:
    int memoisation(int i,int j,string &word1,string &word2,vector<vector<int>>&dp){
        //agar word1 jldi khtm hojaye
        //word 2 ke baaki characters insert hi krne pdege
        if(i>=word1.size()){
            return word2.size()-j;
        }

        //if word2 finishes early
        //delete remaining characters from word1
        if(j>=word2.size()){
            return word1.size()-i;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return memoisation(i+1,j+1,word1,word2,dp);
        }
        else{
            //we have 3 cases
            
            //agar word1 me character replace from from word2
            int replace=1+memoisation(i+1,j+1,word1,word2,dp);

            //agar word1 ka character delete krdia
            int deleteIt=1+memoisation(i+1,j,word1,word2,dp);
            
            //agar word1 me insert krdia current character from word 2
            //because abhi original jo match krna tha word1 ka char wo match hona bcha h
            int insert=1+memoisation(i,j+1,word1,word2,dp); 

            return dp[i][j]= min({replace,deleteIt,insert});
        }
    }

    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memoisation(0,0,word1,word2,dp);
    }
};