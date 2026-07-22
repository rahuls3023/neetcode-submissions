class Solution {
public://approach 3-> max heap
//Push all elements and remove the largest k - 1 times.
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;

        for(int num:nums){
            pq.push(num);
        }
         // Remove the largest element k-1 times.
        // The top element is the kth largest.
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};