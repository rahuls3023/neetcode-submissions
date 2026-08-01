class Solution {
public:
    int memoisation(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
         int m = matrix.size();
        int n = matrix[0].size();

        if(dp[i][j]!=-1) return dp[i][j];

        int longestPath=1;// Current cell itself forms a path of length 1

        // we can go in 4 directions from current i,j

        int up=0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){//ek to out of bound nhi and 2nd condition agar next element current se bda h to hi call krege i-1 ki.
            up=memoisation(i-1,j,matrix,dp);
        }

        int down=0;
        if(i+1<m && matrix[i+1][j]>matrix[i][j]){
            //row+1 wala element > current row ka element
            down=memoisation(i+1,j,matrix,dp);
        }

        int left=0;
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            //if row,col-1 element> current element
            left=memoisation(i,j-1,matrix,dp);
        }

        int right=0;
        if(j+1<n && matrix[i][j+1]>matrix[i][j]){
            //if row , col+1 element> current element.
            right=memoisation(i,j+1,matrix,dp);
        }

         return dp[i][j]= 1 + max({up, down, left, right}); 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int answer = 0;

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                answer=max(answer,memoisation(i,j,matrix,dp));
            }
        }
        return answer;
    }
};
