class Solution {
public://better approach-> o{m+n}space
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<bool>row(m,false);
        vector<bool>col(n,false);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    //mark both col and row as true
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

        //now traverse matrix and make row and col 0 wherver condition satisfies

       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==true || col[j]==true){
                    matrix[i][j]=0;
                }
            }
        }
    }
};