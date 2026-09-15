class Solution {
public://approach 3-> sorting and 2 pointer
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>>originalIndex;

       for(int i=0;i<nums.size();i++){
            originalIndex.push_back({nums[i],i});
       } 

       //now sort the array
       sort(originalIndex.begin(), originalIndex.end());

       //now apply 2 pointer
       int left=0;
       int right=nums.size()-1;

       while(left<right){
         int sum = originalIndex[left].first +
                      originalIndex[right].first;

            if(sum==target){
                 int index1 = originalIndex[left].second;
                int index2 = originalIndex[right].second;

                // Smaller index should come first
                if (index1 < index2) {
                    return {index1, index2};
                } else {
                    return {index2, index1};
                }
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
       }
       return {};
    }
};
