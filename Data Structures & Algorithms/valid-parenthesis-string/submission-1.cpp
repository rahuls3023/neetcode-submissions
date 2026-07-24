class Solution {
public://memoisation
    bool memoisation(int i,int open,string &s,vector<vector<int>>&dp){
        if(i==s.size()){
            if(open==0){
                return true;
            }
            else return false;
        }

        if(dp[i][open]!=-1) return dp[i][open];

        bool isValid=false;
        if(s[i]=='('){
            isValid=isValid | memoisation(i+1,open+1,s,dp);
        }
        else if(s[i]=='*'){
            //check for all 3
            //ek ek baar 3ino leke dekho

            isValid=isValid | memoisation(i+1,open+1,s,dp);//agar * ko ( lete hai to
            isValid=isValid | memoisation(i+1,open,s,dp);//agar "" lete h * ko
            if(open>0){
                isValid=isValid | memoisation(i+1,open-1,s,dp);//agar * ko ) lete h
            }
        }
        else  if(s[i]==')'){
            // ')' milgya
            //open count atleast > 0 hona chaiye

            if(open>0){
                isValid|=memoisation(i+1,open-1,s,dp); 
            }
        }
        return dp[i][open]= isValid;
    }
    bool checkValidString(string s) {
        int open=0;
        int n=s.length();
       vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memoisation(0,open,s,dp);
    }
};