class Solution {
public://better approach-> using negative marking method
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int index=abs(nums[i]);

            if(nums[index]<0){
                 // if already visited then return index bcz pehle se negative hoga
                // return index;
                ans=index;
                break;
            }
            else{
                //visited marks kr rhe h
                nums[index]=nums[index]*-1;
            }
        }
        return ans;
    }
};
