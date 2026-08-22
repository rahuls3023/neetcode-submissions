class Solution {
public://brute force-> for every elements in nums1 search for next greater in nums2;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size());

        for(int i=0;i<nums1.size();i++){
            int currentElement=nums1[i];
            int nextGreater=-1;

            int j;
            for(j=0;j<nums2.size();j++){
                if(nums2[j]==currentElement){
                    break;
                }
            }
            //find greater element for nums1[i] in the right from index j
            for(int k=j+1;k<nums2.size();k++){
                if(nums2[k]>currentElement){
                    nextGreater=nums2[k];
                    break;
                }
            }
            ans[i]=nextGreater;
        }
        return ans;
    }
};