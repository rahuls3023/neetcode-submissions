class Solution {
public://another approach->o(nlogn)+o(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //new intervals ko push kro
        //sort kro
        //merge intervals wala logic lgao.
         intervals.push_back(newInterval);

        // Sort according to starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){

            //check for overlap condition
            if(ans.back()[1]>=intervals[i][0]){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
