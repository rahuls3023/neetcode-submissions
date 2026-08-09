class Solution {
public://approach-1> sorting on the basis of start
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int i=0;
        int j=1;
        int count=0;

        int n=intervals.size();

        while(j<n){
            vector<int>currentInterval=intervals[i];
            vector<int>nextInterval=intervals[j];

            int currStart=currentInterval[0];
            int currEnd=currentInterval[1];

            int nextStart=nextInterval[0];
            int nextEnd=nextInterval[1];


            //check for overlap
            if(currEnd>nextStart){
                //overlap

                //overlap to horha h ab check krna h konsa interval delete krna h

                if(currEnd>nextEnd){
                    //delete current end
                    i=j;
                    j++;
                    count++;
                }
                else{
                    //currEnd<=nextEnd
                    //delete nextend

                    j++;
                    count++;
                }
            }
            else{
                //no overlap-> (currentEnd<=nextStart)
                i==j;
                j++;
            }
        }
        return count;
    }
};
