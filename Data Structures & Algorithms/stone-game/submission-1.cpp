class Solution {
public:
    int memoisation(int start,int end,vector<int>&piles,vector<vector<int>>&dp){
        if(start>end) return 0;

        if(start==end) return piles[start];

        //dp[start][end]=maximum score difference (current player score - opponent score) that the current player can achieve using piles from index start to end.

        if(dp[start][end]!=-1) return dp[start][end];

        //agar shuru se le 
        int PickfromStart=piles[start]-memoisation(start+1,end,piles,dp);

        //end se le
        int PickFromEnd=piles[end]-memoisation(start,end-1,piles,dp);

        return dp[start][end]= max(PickfromStart,PickFromEnd);
    }
    bool stoneGame(vector<int>& piles) {
       int n=piles.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       int ans=memoisation(0,n-1,piles,dp);

       if(ans>=0) return true;
       else return false; 
    }
};