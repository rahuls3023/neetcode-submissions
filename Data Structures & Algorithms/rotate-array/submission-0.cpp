class Solution {
public: // brute force -> using extra space
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        vector<int> rotatedArray;

        // Store the last k elements first
        int startIndex = n - k;

        while(startIndex < n) {
            rotatedArray.push_back(nums[startIndex]);
            startIndex++;
        }

        // Store the remaining first n-k elements
        int currentIndex = 0;

        while(currentIndex < n - k) {
            rotatedArray.push_back(nums[currentIndex]);
            currentIndex++;
        }

        // Copy rotated array back to nums
        int index = 0;

        while(index < n) {
            nums[index] = rotatedArray[index];
            index++;
        }
    }
};