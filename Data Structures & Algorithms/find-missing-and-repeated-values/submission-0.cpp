class Solution {
public://brute force-> using set
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int total=n*n;

        unordered_set<int>st;

        int repeated=-1;
        int missing=-1;

        //find repeated number
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(st.find(grid[i][j])!=st.end()){
                    repeated=grid[i][j];
                }
                st.insert(grid[i][j]);
            }
        }

        //find missing number
        for(int i=0;i<=total;i++){
            if(st.find(i)==st.end()){
                missing=i;
                break;
            }
        }
        return {repeated,missing};
    }
};