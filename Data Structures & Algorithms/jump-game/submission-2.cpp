class Solution {
public://bottom-up
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        vector<bool>dp(n,false);

        // dp[i]=true, means ith index tk pahch skte h hum.
        // dp[i]=false, means ith index tk nhi pahuch skte.

        dp[0]=true;

        for(int j=1;j<n;j++){
            for(int i=j-1;i>=0;i--){
                //i , j ke left side rhega aur check krega kya koi aisa index h jispe i+nums[i] krke hum j pe pahuch jaaye
                if( dp[i]==true && nums[i]+i>=j){
                    //pahuch skte h j pe
                    dp[j]=true;
                    break;//ab baaki check krne ki jarurat nhi h ek baar koi miljaye to
                }
            }
        }
        return dp[n-1];
    }
};