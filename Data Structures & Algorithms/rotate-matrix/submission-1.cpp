class Solution {
public://another approach for reverse
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        //transpose matrix
        for(int i=0;i<row;i++){
            for(int j=i;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse each row
        for(int i=0;i<row;i++){
            for(int j=0;j<row/2;j++){
                swap(matrix[i][j],matrix[i][row-j-1]);
            }
        }
    }
};