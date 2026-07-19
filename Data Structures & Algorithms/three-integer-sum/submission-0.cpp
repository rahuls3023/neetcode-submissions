class Solution {
public://brute force-> o(n3)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
