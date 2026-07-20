class Solution {
public://optimal
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int left=0;
        int right=n-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target) return mid;

            //check kro if left half is sorted
            if(nums[left]<=nums[mid]){
                //iska mtlb left half is sorted

                if(nums[left]<=target && target<nums[mid]){
                    right=mid-1;
                }
                else{
                    //right side milega
                    left=mid+1;
                }
            }

            else{
                //agar left half sorted nhi h
                //check for right half
                //if(nums[mid]<=nums[right])

                if(nums[mid]<target && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};
