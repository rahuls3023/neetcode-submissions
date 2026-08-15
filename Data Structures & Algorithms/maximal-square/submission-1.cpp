class Solution {
public:
    int memoisation(int i,int j,vector<vector<char>>& matrix,vector<vector<int>>&dp){

        if(i<0 || j<0) return 0;

        //agar current cell 0 h to isko include krke square nhi ban skta
        if(matrix[i][j]=='0') return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        //current cell ko bottom-right corner maan rhe h
        //square ki size depend kregi top, left aur diagonal ke minimum par
        //+1 current cell ke lie
        return dp[i][j]= 1 + min({
            memoisation(i-1,j,matrix,dp),      //top
            memoisation(i,j-1,matrix,dp),      //left
            memoisation(i-1,j-1,matrix,dp)     //diagonal
        });
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        //maximum square ki side length store krega
        int result=INT_MIN;

         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        //har cell ko bottom-right corner maan ke check kro
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                //current cell se banne wale square ki maximum side nikalo
                result=max(result,memoisation(i,j,matrix,dp));
            }
        }

        //recursion side length return krta h
        //question area maang rha h -> side * side
        return result*result;
    }
};