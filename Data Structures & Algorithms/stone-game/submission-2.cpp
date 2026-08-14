class Solution {
public:
    int tabulation(vector<int>&piles){
        int n=piles.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));

       // Base case:
        // If only one pile is left, current player takes it.
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

       for(int start=n-1;start>=0;start--){
            for(int end=start+1;end<n;end++){

                 //agar shuru se le 
                int PickfromStart=piles[start]-dp[start+1][end];

                //end se le
                int PickFromEnd=piles[end]-dp[start][end-1];

                dp[start][end]= max(PickfromStart,PickFromEnd);
            }
       }
       return dp[0][n-1];
    }
    bool stoneGame(vector<int>& piles) {
       int ans=tabulation(piles);

       if(ans>=0) return true;
       else return false; 
    }
};