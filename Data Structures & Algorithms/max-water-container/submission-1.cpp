class Solution {
public: // Optimal Approach -> Two Pointers
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = 0;
        int right = n - 1;

        int maximumAmount = 0;

        while (left < right) {

            int width = right - left;
            int containerHeight = min(heights[left], heights[right]);

            int area = width * containerHeight;

            maximumAmount = max(maximumAmount, area);

            // Move the pointer having smaller height.
            // Width decreases anyway, so we look for a taller bar.
            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maximumAmount;
    }
};