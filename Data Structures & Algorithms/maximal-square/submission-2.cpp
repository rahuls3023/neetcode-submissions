class Solution {
public:
    int tabulation(vector<vector<char>>&matrix){
        int m=matrix.size();
        int n=matrix[0].size();

            //dp[i][j] = largest square ki side length
            //jiska bottom-right corner (i,j) h
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        int result=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 //agar current cell 0 h to square nhi ban skta
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }

                //first row ya first column me agar cell 1 h
                //to maximum 1x1 square hi ban skta h
                else if(i==0 || j==0){
                    dp[i][j]=1;
                }
                 else{
                    //current cell ko bottom-right maan rhe h
                    //top, left aur diagonal me jo minimum square h
                    //usi ko current 1 extend kr skta h
                    dp[i][j]=1+min({
                        dp[i-1][j],      //top
                        dp[i][j-1],      //left
                        dp[i-1][j-1]     //diagonal
                    });
                }
                //maximum side length update kro
                result=max(result,dp[i][j]);
            }
        }
         //maximum side length update kro
        return result*result;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        return tabulation(matrix);
    }
};