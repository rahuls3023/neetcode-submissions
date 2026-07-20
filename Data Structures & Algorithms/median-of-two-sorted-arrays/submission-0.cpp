class Solution {
public://brute force
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        vector<int>merged;

         // Store elements of nums1
        for(int i = 0; i < n1; i++) {
            merged.push_back(nums1[i]);
        }

        // Store elements of nums2
        for(int i = 0; i < n2; i++) {
            merged.push_back(nums2[i]);
        }

        //sort this array
        sort(merged.begin(),merged.end());

        int n=merged.size();

        //if size of array is off
        if(n%2!=0){
            return merged[n/2];
        }

         // If total number of elements is even
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};
