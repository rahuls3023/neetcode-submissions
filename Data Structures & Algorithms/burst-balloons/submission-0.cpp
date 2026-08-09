class Solution {
public://ulta direction me jayege -> last ballon to first ballon
//Hum try karenge har k as last burst
    int recursion(int i,int j,vector<int>&nums){
        //base case
        //ballon burst kr rhe h to rukege kab jab ballon hi na bche burst krne ko
        if(i>j) return 0;

        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            // nums[i-1] and nums[j+1] are fixed boundaries for current interval
            // kyuki hum k ko LAST burst maan rahe hain, beech ke sab already burst ho chuke honge

            int coins = nums[i-1]*nums[k]*nums[j+1]
                      + recursion(i,k-1,nums)   // left subarray (independent)
                      + recursion(k+1,j,nums);  // right subarray (independent)

            //k-1 kyuki k already burst ho chuka h

            if(maxi<coins){
                maxi=coins;
            }
        }
        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        //1 ko insert krdo nums ke start and end pe
        //taaki edge balloons ke liye bhi same formula kaam kare (no special cases)
        nums.insert(begin(nums),1);
        nums.push_back(1);

        int n=nums.size();

        //hum sirf original balloons pe kaam karenge (dummy 1s exclude)
        return recursion(1,n-2,nums);
    }
};