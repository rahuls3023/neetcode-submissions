class Solution {
public:
    int memoisation(int index,vector<int>&nums,int n,vector<int>&dp){
        if(index>n){//yaha >= nhi kra kyu is nth index ke house ko bhi chori kr skta hu me islie iski value bhi consider kr skte h
            return 0;
        }

        if(dp[index]!=-1) return dp[index];

        //agar current house me steal kre
        int steal=0;
        steal+=nums[index]+memoisation(index+2,nums,n,dp);

        //skip current house
        int not_steal=0;
        not_steal+=memoisation(index+1,nums,n,dp);

        return dp[index]= max(steal,not_steal);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

         vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);

        //agar first wale me chori krle to last me n-1 as neighbour h to waha to usme chori nhi kr skte
        int stealFirst=memoisation(0,nums,n-2,dp1);
        //agar first me chori nhi kri to n-1 house me chori kr skte h
        int stealSecond=memoisation(1,nums,n-1,dp2);
        return max(stealFirst,stealSecond);

    }
};