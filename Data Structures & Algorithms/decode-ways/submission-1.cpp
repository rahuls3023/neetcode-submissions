class Solution {
public://memoisation
    int memoisation(int index,string &s,vector<int>&dp){
        //base case
        if(index==s.length()) return 1;//1 valid string decode hogyi

        if(s[index]=='0') return 0;//cannot be mapped

        if(dp[index]!=-1) return dp[index];

        //we can choose the characters in group of 1 or in 2

        int takeOne=0;
        takeOne+=memoisation(index+1,s,dp);

        //choose two characters and check if it lies between 10 and 26
        int takeTwo=0;
        if(index+1<s.length()){
            int number=(s[index]-'0')*10+(s[index+1]-'0');

            if(number>=10 && number<=26){
                takeTwo+=memoisation(index+2,s,dp);
            }
        }
        

        return dp[index]= (takeOne+takeTwo);
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+2,-1);
        return memoisation(0,s,dp);
    }
};