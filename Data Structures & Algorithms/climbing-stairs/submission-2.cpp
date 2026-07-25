class Solution {
public:
    int tabulation(int n){
        vector<int>dp(n+1,0);

        dp[0]=1;//base case

        for(int i=1;i<=n;i++){
            int oneStep=0;
            oneStep=dp[i-1];

            int twoStep=0;
            if(i-2>=0){
                twoStep=dp[i-2];
            }

            dp[i]=oneStep+twoStep;
        }
        return dp[n];
    }
    int climbStairs(int n) {
        
        return tabulation(n);
    }
};