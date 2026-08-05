class Solution {
public://using sorting
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));

        vector<vector<int>>ans;

        int n=intervals.size();

        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            //now check for intervals
            if(ans.back()[1]>=intervals[i][0]){
                //ye overlap kr rhe h
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};