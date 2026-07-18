class Solution {
public://approach-1> start from a number search its sequence x+1,x+2.... in array by linear search and store longest.
    bool isPresent(vector<int>&nums,int target){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        int longest=0;

        for(int i=0;i<n;i++){
            int currentNumber=nums[i];
            int currentLength=1;

            while(isPresent(nums,currentNumber+1)){//jab tk uska sequence mil rha hai.
                currentNumber++;
                currentLength++;
            }
            longest=max(longest,currentLength);
        }
        return longest;
    }
};
