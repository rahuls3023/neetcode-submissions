class Solution {
public://brute force
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int>ans;
        vector<bool>used(n,false);

        //process elements according to arr2
        for(int i=0;i<arr2.size();i++){

            for(int j=0;j<arr1.size();j++){
                //search for every occurence of  element arr2[i] in arr1[j]

                if(!used[j] && arr1[j]==arr2[i]){
                    ans.push_back(arr1[j]);
                    used[j]=true;
                }
            }
        }

        //store remaining elements
        vector<int>remaining;

        for(int i=0;i<n;i++){
            if(!used[i]){
                remaining.push_back(arr1[i]);
            }
        }
        // Remaining elements must be ascending
        sort(remaining.begin(), remaining.end());

         // Add remaining elements
        for(int x : remaining) {
            ans.push_back(x);
        }

        return ans;
    }
};