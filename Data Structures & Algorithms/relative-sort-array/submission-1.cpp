class Solution {
public://map approach
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;

        //count freq of each element of arr1
        for(auto it:arr1){
            mp[it]++;
        }

        vector<int>ans;

        //process element according to arr2
        for(int x:arr2){

            //add x according to its frequency
            while(mp[x]>0){
                ans.push_back(x);
                mp[x]--;
            }
        }

        //store remaining elements
        vector<int>remaining;

        for(auto it:mp){
            while(it.second>0){
                remaining.push_back(it.first);
                it.second--;
            }
        }
        // Remaining elements in ascending order
        sort(remaining.begin(), remaining.end());

        // Add remaining elements
        for(int x : remaining) {
            ans.push_back(x);
        }

        return ans;
    }
};