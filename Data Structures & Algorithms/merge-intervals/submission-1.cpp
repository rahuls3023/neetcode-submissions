class Solution {
public://brute force type-> sorting.
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        sort(begin(intervals),end(intervals));

        int n=intervals.size();

        for(int i=0;i<n;i++){
            int left=intervals[i][0];
            int right=intervals[i][1];

            //check if this interval is already merged or not
            //to skip the interval if its already been included in current range
            if(!ans.empty() && right<=ans.back()[1])continue;

            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<=right){
                    //merge
                    right=max(right,intervals[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({left,right});
        }
        return ans;
    }
};