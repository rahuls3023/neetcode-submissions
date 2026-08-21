class Solution {
public://approach-1>
    vector<int> sortArray(vector<int>& nums) {
        sort(begin(nums),end(nums));
        return nums;
    }
};