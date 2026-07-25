class Solution {
public://optimal-> using prefix and suffix
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;

        // the maximum product either lies in the prefix part or in the suffix part
        // if there is odd count of negative numbers in array, we cannot take all, so either the maximum product will lie in the suffix part of one of the negative number or in the prefix part.
        // Hence, we traverse from both directions and take the maximum product obtained in either traversal.

        int pref=1;
        for(int i=0;i<n;i++){
            if(pref==0){
                //it means this is starting of new subarray
                pref=1;
            }
            pref*=nums[i];
            ans=max(ans,pref);
        }

        //suffix
        int suff=1;
        for(int i=n-1;i>=0;i--){
            if(suff==0){
               //it means this is starting of new subarray
                suff=1; 
            }
            suff*=nums[i];
            ans=max(ans,suff);
        }
        return ans;
    }
};