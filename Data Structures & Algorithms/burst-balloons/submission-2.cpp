class Solution {
public:
    int tabulation(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){//i tk kyuki i==j bhi ek valid subproblem h

              int maxi=INT_MIN;
                for(int k=i;k<=j;k++){

                    int coins = nums[i-1]*nums[k]*nums[j+1]
                            + dp[i][k-1]   // left subarray (independent)
                            + dp[k+1][j];  // right subarray (independent)

                    //k-1 kyuki k already burst ho chuka h

                    if(maxi<coins){
                        maxi=coins;
                    }
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n-2];
    }

    int maxCoins(vector<int>& nums) {
        //1 ko insert krdo nums ke start and end pe
        //taaki edge balloons ke liye bhi same formula kaam kare (no special cases)
        nums.insert(begin(nums),1);
        nums.push_back(1);

      
        return tabulation(nums);
    }
};