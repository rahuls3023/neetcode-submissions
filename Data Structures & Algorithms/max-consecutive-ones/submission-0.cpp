class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countone=0;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                countone++;
                ans=max(ans,countone);
            }
            else{
                countone=0;
            }
        }
        return ans;
    }
};