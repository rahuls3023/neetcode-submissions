class Solution {
public://hashmap and min heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //this approach is better than max heap because isme kbhi bhi heap ka size > k nhi hoga.

        //step-1>
        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        // Step 2: Min Heap -> {frequency, element}
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Step 3: Keep only top k frequent elements
        for(auto it:mp){
            pq.push({it.second,it.first});

            if(pq.size()>k){
                pq.pop();
            }
        }

        //step-4> extract ans;
         // Step 4: Extract answer
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
