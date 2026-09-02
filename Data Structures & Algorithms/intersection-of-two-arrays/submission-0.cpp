class Solution {
public://approach 1-> using map
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        unordered_set<int>st;

        vector<int>ans;

        for(auto it:nums1){
            mp[it]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]!=0 && st.find(nums2[i])==st.end()){
                ans.push_back(nums2[i]);
                st.insert(nums2[i]);
            }
        }
        return ans;
    }
};