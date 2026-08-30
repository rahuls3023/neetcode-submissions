class Solution {
public://brute force
    bool check(vector<int>& nums) {
         int n = nums.size();

        // try every possible rotation
        for(int k = 0; k < n; k++) {

            // initially assume that the current rotation is sorted
            bool sorted = true;

            // check whether the current rotation is sorted
            // compare only adjacent elements
            // don't compare the last element with the first
            for(int i = 0; i < n - 1; i++) {

                // get current element after virtually rotating by k positions
                int current = nums[(i + k) % n];

                // get next element after virtually rotating by k positions
                int next = nums[(i + k + 1) % n];

                // if current > next, the rotation is not sorted
                if(current > next) {
                    sorted = false;
                    break;
                }
            }

            // if any rotation is sorted, return true
            if(sorted == true) {
                return true;
            }
        }

        // if no rotation is sorted, return false
        return false;
    }
};