class Solution {
public://brute force-> using extra space
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans(m+n);

        int i=0;
        int j=0;
        int k=0;

        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans[k]=nums1[i];
                k++;
                i++;
            }
            else{
                ans[k]=nums2[j];
                k++;
                j++;
            }
        }
         while(i<m){
            ans[k]=nums1[i];
            i++;
            k++;
        }

        while(j<n){
            ans[k]=nums2[j];
            j++;
            k++;
        }
       // Copy merged array back into nums1
        for (int index = 0; index < m + n; index++) {
            nums1[index] = ans[index];
        }
    }
};