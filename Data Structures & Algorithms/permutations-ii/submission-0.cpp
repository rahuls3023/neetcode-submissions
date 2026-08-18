class Solution {
public://approach-1>used[] + set<vector<int>>
    int n;
    void solve(vector<int>&nums,set<vector<int>>&st,vector<int>&temp,vector<bool>&used){
        //base case
        if(temp.size()==n){
            st.insert(temp);
            return;
        }

        for(int i=0;i<n;i++){
            //agar current index already use ho chuka h
            if(used[i]==true) continue;

            temp.push_back(nums[i]);
            used[i]=true;


            solve(nums,st,temp,used);

            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        n=nums.size();

        vector<bool>used(n,false);

        solve(nums,st,temp,used);

        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};