class Solution {
public://approach-2>reverse approach
    void rotate(vector<int>& nums, int k) {

        int n=nums.size();

        if(n==0)return;
        
        k=k%n;
        
        reverse(begin(nums),end(nums));

        reverse(nums.begin(),nums.begin()+k);

        reverse(nums.begin()+k,nums.end());
    }
};