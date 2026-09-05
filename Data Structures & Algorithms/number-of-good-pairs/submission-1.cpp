class Solution {
public://optimal
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>freq(200001,0);

        int total=0;

        for(int i=0;i<nums.size();i++){
            int x=nums[i]+100000;//avoid negative indexes

            total+=freq[x];//previous same elements
            freq[x]++;//current element ko add kro
        }
        return total;
    }
};