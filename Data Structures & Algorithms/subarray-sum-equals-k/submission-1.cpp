class Solution {
public://optimal-> prefixsum
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;//{prefixsum,frequency}
        int n=nums.size();

        int prefixSum=0;

        int total=0;

        mp[0]=1;//"Before the array starts, there is one prefix sum equal to 0."

        for(int i=0;i<n;i++){
            prefixSum+=nums[i];

            int remaining=prefixSum-k;

            if(mp.find(remaining)!=mp.end()){
                total+=mp[remaining];
            }
            mp[prefixSum]++;
        }
        return total;
    }
};