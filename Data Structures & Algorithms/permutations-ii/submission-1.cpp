class Solution {
public://approach-2> using sort + used[]
    int n;
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,vector<bool>&used){

        //base case
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            //current index already used ho chuka h
            if(used[i]==true) continue;

            //"agar mere jaisa previous element hai, aur wo current path me use nahi hua, toh mujhe bhi is recursion level par choose mat karo"

            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false){
                continue;
            }

            temp.push_back(nums[i]);
            used[i]=true;

            solve(nums,ans,temp,used);

            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;

        n=nums.size();

        sort(begin(nums),end(nums));

        vector<bool>used(n,false);

        solve(nums,ans,temp,used);

        return ans;
    }
};