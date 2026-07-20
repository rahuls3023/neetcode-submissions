class Solution {
public://better approach-> using max heap
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxheap;
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            maxheap.push({nums[i],i});

            //check the top element if it is outisde of the range of current window.

            while(maxheap.top().second<=i-k){
                maxheap.pop();
            }

            // Once the first complete window is formed (i >= k-1),
            // every iteration represents a valid window, so store its maximum.
            if(i>=k-1){
                ans.push_back(maxheap.top().first);
            }
        }
        return ans;
    }
};
