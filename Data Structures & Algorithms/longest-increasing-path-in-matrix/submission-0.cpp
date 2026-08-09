class Solution {
public:
    int recursion(int i,int j,vector<vector<int>>&matrix){
         int m = matrix.size();
        int n = matrix[0].size();

        int longestPath=1;// Current cell itself forms a path of length 1

        // we can go in 4 directions from current i,j

        int up=0;
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){//ek to out of bound nhi and 2nd condition agar next element current se bda h to hi call krege i-1 ki.
            up=recursion(i-1,j,matrix);
        }

        int down=0;
        if(i+1<m && matrix[i+1][j]>matrix[i][j]){
            //row+1 wala element > current row ka element
            down=recursion(i+1,j,matrix);
        }

        int left=0;
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            //if row,col-1 element> current element
            left=recursion(i,j-1,matrix);
        }

        int right=0;
        if(j+1<n && matrix[i][j+1]>matrix[i][j]){
            //if row , col+1 element> current element.
            right=recursion(i,j+1,matrix);
        }

         return 1 + max({up, down, left, right}); 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int answer = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                answer=max(answer,recursion(i,j,matrix));
            }
        }
        return answer;
    }
};
