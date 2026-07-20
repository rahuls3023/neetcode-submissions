/*
Story Points:

1. Whenever a new element nums[i] comes,
   first remove all indices from the front
   that are outside the current window.

2. Now compare nums[i] with elements at the back.
   If nums[i] is greater, pop_back() all smaller elements
   because they can never become the maximum while nums[i]
   is inside the window.

3. Push the current index i into the deque.
   The deque always stores indices in decreasing
   order of their values.

4. Once the first complete window is formed (i >= k-1),
   the front of the deque always stores the index of
   the maximum element for the current window.
*/

class Solution {
public://optimal approach-> using deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;//motononic decreasing queue
        vector<int>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            
            //step-1> remove indices that are out of window
            //hum front se hi remove kr rhe h kyuki front me hi purane window ke elemnts ho skte h as back se to new window ke elements push ho rhe h.
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }


            // Step-2: Remove all smaller elements from the back.
            //
            // We remove from the back because if nums[i] is greater than them,
            // those smaller elements can never become the maximum while nums[i]
            // remains inside the current window.
            //
            // We do NOT remove from the front because the front always stores
            // the maximum element of the current window. Removing it unnecessarily
            // would lose the current maximum.aximum loss ho jayega, isiye back se.
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            //step-3> push currrent index
            dq.push_back(i);

            //step-4> jese hi current size ki window miljaye, uske front wala hi maximum hoga
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
