class Solution {
public:
    void recursion(int n,int k,int start,vector<vector<int>>&ans,vector<int>&temp){
        //base case
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int j=start;j<=n;j++){
            temp.push_back(j);
            recursion(n,k,j+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        recursion(n,k,1,ans,temp);
        return ans;
    }
};