class Solution {
public://optimal-> remainder approach
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;//{remainder,frequency}

        mp[0]=1;//remainder initially 0 ek baar

        int prefixSum=0;


        int ans=0;

        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];

            int remainder=prefixSum%k;//prefixsum ka remainder

            if(remainder<0){
                remainder+=k;
            }

            //same remainder, means divisible array
            ans+=mp[remainder];

            // current remainder ko store karo
            mp[remainder]++;
        }
        return ans;
    }
};