class Solution {
public://approach-3> frequency array
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>freq(1001,0);

        //count freq of elements of arr1
        for(auto it:arr1){
            freq[it]++;
        }

        vector<int>ans;

        //process elements according to arr2
        for(int x:arr2){

            //add x according to freq
            while(freq[x]>0){
                ans.push_back(x);
                freq[x]--;
            }
        }

        //remaining elements are automatically found
        for(int i=0;i<1001;i++){
            while(freq[i]>0){
                ans.push_back(i);
                freq[i]--;
            }
        }
        return ans;
    }
};