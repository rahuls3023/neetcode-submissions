class Solution {
public:
    vector<vector<int>>result;
    unordered_set<int>st;
    int n;

    void solve(vector<int>&nums,vector<int>&temp){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }

        //har ek element se permutation start krni hai isliye for loop 0 se chlayege , isliye koi index nhi lerhe recursion me aur fir har ek call ke baad firse 0th index se check krna h aage permutation.

        
        for(int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(nums,temp);

                temp.pop_back();
                st.erase(nums[i]);
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        solve(nums,temp);
        return result;
    }
};