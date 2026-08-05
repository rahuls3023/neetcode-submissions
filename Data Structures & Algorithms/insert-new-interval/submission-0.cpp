class Solution {
public://simple traversing approach-> optimal
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();

        vector<vector<int>>ans;

        bool inserted=false;

        for(int i=0;i<n;i++){

            ///if no overlap
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
            }
            //current inerval completely lies after new interval
            else if(intervals[i][0]>newInterval[1]){
                //ab ho skta h usse pehle aayega new interval
                if(inserted==false){
                    ans.push_back(newInterval);
                    inserted=true;
                }
                //push the current interval
                ans.push_back(intervals[i]);
            }
            else{
                //overlap condition
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        //agar new interval abtk push nhi hua iska mtlb last me ayega
        if(!inserted){
            ans.push_back(newInterval);
        }
        return ans;
    }
};