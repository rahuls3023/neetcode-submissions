class Solution {
public:
    int m;
    int tabulation(vector<vector<int>>& triangle){
        m=triangle.size();

        vector<vector<int>> dp(m+1, vector<int>(m+1,0));
        
        //base case for i==m-1;
        //Last row ke har element ka minimum path wahi khud hai

        for(int j=0;j<triangle[m-1].size();j++){//m-1 is for last row
            dp[m-1][j] = triangle[m-1][j];
        }

        //bottom to top
        for(int row=m-2; row>=0; row--){
            for(int col=0; col<=row; col++){

                int down = triangle[row][col] + dp[row+1][col];
                int diagonal = triangle[row][col] + dp[row+1][col+1];

                dp[row][col] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return tabulation(triangle);
    }
};