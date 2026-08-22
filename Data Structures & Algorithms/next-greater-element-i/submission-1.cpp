class Solution {
public://optimal
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        unordered_map<int,int>mp;

        stack<int>st;

        for(int i=n2-1;i>=0;i--){
             //current se chota ya uske equal elements pop kro
             while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
             }

             if(st.empty()){
                mp[nums2[i]]=-1;
             }
             else{
                mp[nums2[i]]=st.top();
             }
             st.push(nums2[i]);
        }   

        vector<int>ans(n1);
        for(int i=0;i<n1;i++){
            int currentNum=nums1[i];

            int nextGreaterOfCurrent=mp[currentNum];

            ans[i]=nextGreaterOfCurrent;
        }
        return ans;
    }
};