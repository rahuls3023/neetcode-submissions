class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         // Values are in range [-100, 100]
        // So total possible values = 201
        vector<int> freq(201, 0);

        // Count frequency of each element
        // +100 is used as an offset to handle negative values
        for(int x : nums) {
            freq[x + 100]++;
        }

        // Store {value, frequency}
        vector<pair<int, int>> v;

        for(int i=0;i<=200;i++){
            if(freq[i]>0){
                // Convert index back to original value
                int value = i - 100;

                v.push_back({value,freq[i]});
            }
        }

        //sort according to the required condition
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            //condition 1
            //smaller frequency comes first;
            if(a.second!=b.second){
                return a.second<b.second;
            }
             // Condition 2:
            // If frequency is same, larger value comes first
            return a.first > b.first;
        });

         vector<int> ans;

         for(auto it:v){
            int value = it.first;
            int frequency = it.second;

            while(frequency--) {
                ans.push_back(value);
            }
         }
         return ans;
    }
};