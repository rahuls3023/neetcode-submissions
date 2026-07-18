class Solution {
public://brute force-> hashmap and then sorting in descending order
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        // Step 2: Store ( frequency,element) pairs in a vector
        vector<pair<int, int>> arr;

        for(auto it:mp){
            auto number=it.first;
            auto freq=it.second;

            arr.push_back({freq,number});
        }

        //because it will be easy to sort on the basis of first elements, as we have to sort on the basis of frequency

        //step-3> sort it in descending order
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        //step-4> tke out k elements
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
