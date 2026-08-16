class Solution {
public:
    // TC: O(numRows²)
    // SC: O(numRows²) for the returned answer.
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=0;i<numRows;i++){
            vector<int>path(i+1,1);

            for(int j=1;j<i;j++){
                path[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(path);
        }
        return ans;
    }
};