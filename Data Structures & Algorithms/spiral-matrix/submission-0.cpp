class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int top = 0;
        int bottom = m - 1;
        int right = n - 1;

        while (top <= bottom && left <= right) {

            // Traverse the top row from left to right.
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse the right column from top to bottom.
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse the bottom row only if a valid row remains.
            // Without this check, in a single remaining row case,
            // the same row would be traversed again (duplicate elements).
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse the left column only if a valid column remains.
            // Without this check, in a single remaining column case,
            // the same column would be traversed again (duplicate elements).
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};