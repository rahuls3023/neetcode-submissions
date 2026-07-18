class Solution {
public://approach-2> hashmap and max heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto it:nums){
            mp[it]++;
        }

        //create a max heap
        priority_queue<pair<int,int>>pq;//{frequency,element}

        //push into maxheap
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

         // Step 3: Pop top k frequent elements
        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
