class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

        int count=0;//count how many times sorted order breaks

        for(int i=0;i<n;i++){
             //agar current element next element se bada hai
            //to yaha sorted order break ho rha hai
            //%n se last element ko first element se bhi compare krenge

            if(nums[i]>nums[(i+1)%n]){
                count++;
            }
            //sorted and rotated array me maximum ek hi break ho sakta hai
            if(count>1){
                return false;
            }
        }
        return true;
    }
};