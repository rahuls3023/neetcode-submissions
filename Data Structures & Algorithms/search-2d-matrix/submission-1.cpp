class Solution {
public://optimal approach-> flatten+binary search.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        int low=0;
        int high=cols*rows-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            // mid represents the index in the virtual 1D (flattened) array.
            // Convert this 1D index into the corresponding 2D matrix indices (row and column).

            int row=mid/cols;
            int col=mid%cols;

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};
