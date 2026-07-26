// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n=pairs.size();

         // Stores array state after every insertion
        vector<vector<Pair>> ans;

         // Empty array → no states
        if (n == 0) {
            return ans;
        }

        // Store the initial state of the array
        ans.push_back(pairs);

        for(int i=1;i<n;i++){
            Pair currentPair = pairs[i];
            int j=i-1;

            while(j>=0 && pairs[j].key>currentPair.key){
                pairs[j+1]=pairs[j];
                j--;
            }
             // Insert current pair at its correct position
            pairs[j + 1] = currentPair;

            // Store array state after this insertion
            ans.push_back(pairs);
        }
        return ans;
    }
};
