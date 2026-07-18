class Solution {
public://approach-4> without extra space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int>result(n);//left product store kr rhe h pehle
        result[0]=1;

        for(int i=1;i<n;i++){
            result[i]=result[i-1]*nums[i-1];
        }
         //sb same hi rhega bass alag se left product lene ki jagah , result me store kr lege left product and ek right product variable le lege

         int rightProduct=1;

         for(int i=n-1;i>=0;i--){
            result[i]=result[i]*rightProduct;

            rightProduct*=nums[i];
         }
         return result;
    }
};
