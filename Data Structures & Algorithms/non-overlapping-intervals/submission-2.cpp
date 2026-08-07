class Solution {
public://approach-2> almost identical to 1 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int i=1;
        vector<int>prev=intervals[0];
        int count=0;
        int n=intervals.size();

        while(i<n){
            int currentStart=intervals[i][0];
            int currentEnd=intervals[i][1];

            int prevEnd=prev[1];

            //check for overlap
            
            if(prevEnd<=currentStart){
                //noo overlap
                prev=intervals[i];
                i++;
            }
            //overlap case
            //now we decide which interval to remove
            else if(currentEnd>=prevEnd){
                //remove currentend
                i++;
                count++;
            }
            else if(currentEnd<prevEnd){
                prev=intervals[i];
                i++;
                count++;
            }
        }
        return count;
    }
};
