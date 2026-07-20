class Solution {
public://optimal approach
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If the current search range is already sorted,
            // then the leftmost element is the minimum.
            if (nums[left] <= nums[right]) {
                return nums[left];
            }

            // Otherwise, the current search range is rotated.
            if (nums[left] > nums[right]) {

                // Determine which side contains the minimum element.

                if (nums[mid] > nums[right]) {
                    // Mid lies in the left sorted portion.
                    // Therefore, the minimum must be on the right side.
                    left = mid + 1;
                }
                else {
                    // Mid lies in the right sorted portion.
                    // Mid itself can be the minimum,
                    // so we cannot discard it.
                    right = mid; // not mid - 1
                }
            }
        }

        return nums[left];
    }
};