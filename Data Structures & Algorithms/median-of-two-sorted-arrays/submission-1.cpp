class Solution {
public://better approach-> store all elements using 2 pointer then find median
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int i=0;//for nums1
        int j=0;//for nums2

        vector<int>merged;

        while(i<n1 && j<n2){//this loop will run until any one array finishes first;
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1){
             merged.push_back(nums1[i]);
            i++;
        }

        while(j<n2){
            merged.push_back(nums2[j]);
            j++;
        }

        //now we got full sorted array
        int n=merged.size();

        //if size of array is off
        if(n%2!=0){
            return merged[n/2];
        }

         // If total number of elements is even
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};