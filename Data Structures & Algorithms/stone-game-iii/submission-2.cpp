class Solution {
public:
    int n;
    int memoisation(int index,vector<int>&stoneValue,vector<int>&dp){
        if(index>=stoneValue.size()) return 0;

        //dp[index]=maximum score difference (current player score - opponent score) that the current player can achieve starting from index till the end.
        
        if(dp[index]!=-1) return dp[index];

        int total=0;
        int best=INT_MIN;

        for(int take=1;take<=3;take++){

            if(index+take-1>=stoneValue.size())break;

            total+=stoneValue[index+take-1];

            best=max(best,total-memoisation(index+take,stoneValue,dp));
        }
        return dp[index]= best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int>dp(n+1,-1);
        int diff=memoisation(0,stoneValue,dp);

        if(diff>0){
            return "Alice";
        }
        else if(diff==0){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};