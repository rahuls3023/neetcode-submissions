class Solution {
public://better approach-> using 2 vector arrray of left and right product
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int>left(n);
        vector<int>right(n);

        left[0]=1;//0th index ke left me kuch nhi hoga
        right[n-1]=1;//nth index ke right me kuch nhi hoga

        //calculate left product
        for(int i=1;i<n;i++){
            left[i]=nums[i-1]*left[i-1];
        }
        //calculate right product
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};
