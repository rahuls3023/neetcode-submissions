class Solution {
public://tabulation

    int tabulation(string &s){
        int n=s.length();
        vector<int>dp(n+2,0);

        // dp[index] = number of ways to decode the substring from index to n-1

        // Empty string has one valid decoding
        dp[n]=1;

        for(int index=n-1;index>=0;index--){

            if(s[index]=='0'){//baase case for 0
                dp[index]=0;
                continue;
            }

            int takeOne=0;
            takeOne+=dp[index+1];

            //choose two characters and check if it lies between 10 and 26
            int takeTwo=0;
            if(index+1<s.length()){
                int number=(s[index]-'0')*10+(s[index+1]-'0');

                if(number>=10 && number<=26){
                    takeTwo+=dp[index+2];
                }
            }

            dp[index]=takeOne+takeTwo;
        }
        return dp[0];
    }
    int numDecodings(string s) {
        return tabulation(s);
    }
};