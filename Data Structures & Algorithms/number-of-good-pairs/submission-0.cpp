class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int total=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i<j && nums[i]==nums[j]){
                    total++;
                }
            }
        }
        return total;
    }
};