class Solution {
public://better apporach
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        set<vector<int>>st;

        for(int i=0;i<n;i++){
            unordered_set<int> hashSet;
            for(int j=i+1;j<n;j++){
                int thirdSum=-(nums[i]+nums[j]);

                if(hashSet.find(thirdSum)!=hashSet.end()){
                    //we go the triplet
                     vector<int> temp = {nums[i], nums[j], thirdSum};

                     sort(temp.begin(),temp.end());

                     st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
