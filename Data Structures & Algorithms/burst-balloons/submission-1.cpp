class Solution {
public://ulta direction me jayege -> last ballon to first ballon
//Hum try karenge har k as last burst
    int memoisation(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        //base case
        //ballon burst kr rhe h to rukege kab jab ballon hi na bche burst krne ko
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            // nums[i-1] and nums[j+1] are fixed boundaries for current interval
            // kyuki hum k ko LAST burst maan rahe hain, beech ke sab already burst ho chuke honge

            int coins = nums[i-1]*nums[k]*nums[j+1]
                      + memoisation(i,k-1,nums,dp)   // left subarray (independent)
                      + memoisation(k+1,j,nums,dp);  // right subarray (independent)

            //k-1 kyuki k already burst ho chuka h

            if(maxi<coins){
                maxi=coins;
            }
        }
        return  dp[i][j]= maxi;
    }

    int maxCoins(vector<int>& nums) {
        //1 ko insert krdo nums ke start and end pe
        //taaki edge balloons ke liye bhi same formula kaam kare (no special cases)
        nums.insert(begin(nums),1);
        nums.push_back(1);

        int n=nums.size();

        //hum sirf original balloons pe kaam karenge (dummy 1s exclude)
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memoisation(1,n-2,nums,dp);
    }
};