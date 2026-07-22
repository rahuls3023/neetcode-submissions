class Solution {
public:
    // Optimal Approach -> O(1) extra space
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // These booleans remember whether the original
        // first row or first column contained any zero.
        // We need them because later we will use the
        // first row and first column as markers.
        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        // Check whether the first row originally contains a zero.
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowImpacted = true;
                break;
            }
        }

        // Check whether the first column originally contains a zero.
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColImpacted = true;
                break;
            }
        }

        // Traverse the remaining matrix (excluding first row and first column).
        // Whenever a zero is found:
        // 1. Mark its entire row by making the first element of that row zero.
        // 2. Mark its entire column by making the first element of that column zero.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Row marker
                    matrix[0][j] = 0; // Column marker
                }
            }
        }

        // Traverse the remaining matrix again.
        // If either the row marker or the column marker is zero,
        // make the current element zero.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // If the original first row had any zero,
        // make the entire first row zero.
        if (firstRowImpacted) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // If the original first column had any zero,
        // make the entire first column zero.
        if (firstColImpacted) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};