class Solution {
public:
    int n;
    int tabulation(vector<int>&stoneValue){
        n=stoneValue.size();
        vector<int>dp(n+1,0);

        for(int index=n-1;index>=0;index--){
            int total=0;
            int best=INT_MIN;

            for(int take=1;take<=3;take++){

                if(index+take-1>=stoneValue.size())break;

                total+=stoneValue[index+take-1];

                best=max(best,total-dp[index+take]);
            }
            dp[index]= best;
        }
        return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int diff=tabulation(stoneValue);

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