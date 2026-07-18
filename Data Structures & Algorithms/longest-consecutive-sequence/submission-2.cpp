class Solution {
public://approach-2> sorting
    int longestConsecutive(vector<int>& nums) {

         if (nums.empty()) return 0;//edge case
         
        sort(nums.begin(),nums.end());
        int currentLength=1;
        int longest=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                //sequence mila
                currentLength++;
            }
            else if(nums[i]==nums[i-1]) continue;//duplicate
            else{
                //nhi h sequence, to reset currentlength
                currentLength=1;
            }
            longest=max(currentLength,longest);
        }
        return longest;
    }
};
