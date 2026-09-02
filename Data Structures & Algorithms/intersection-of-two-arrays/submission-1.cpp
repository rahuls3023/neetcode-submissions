class Solution {
public://approach-2> sorting+2 pointer
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));

        int i=0;
        int j=0;

        vector<int>ans;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                //same element h
                 // same element
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};