class Solution {
public:
    int m;
    int memoisation(int row,int col,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        //base case
        if(row==triangle.size()-1){
            return triangle[row][col];
        }

        // dp[row][col] = minimum path sum from (row,col) to the last row

        if(dp[row][col]!=INT_MAX) return dp[row][col];

        int down=triangle[row][col]+memoisation(row+1,col,triangle,dp);
        int diagonal=triangle[row][col]+memoisation(row+1,col+1,triangle,dp);

        return  dp[row][col]= min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();

        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MAX));
        return memoisation(0,0,triangle,dp);
    }
};