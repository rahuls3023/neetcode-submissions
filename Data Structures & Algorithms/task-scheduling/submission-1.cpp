class Solution {
public://brute force simulation using sorting
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);

        //count the freq
        for(auto it:tasks){
            freq[it-'A']++;
        }
        int time=0;

        while(true){
            //highest frequency tasks comes first
            sort(freq.begin(),freq.end(),greater<int>());//descending order

             // No task is remaining
            if (freq[0] == 0) {
                break;
            }
            
            int executed=0;

            //one cycle can contain atmost n+1 different tasks.
            for(int i=0;i<=n;i++){
                if(i<26 && freq[i]>0){
                    freq[i]--;
                    executed++;
                }
            }

            //check whether tasks are still remaining
            bool tasksRemaining=false;

            //tasks are still remaining
            for(int count:freq){
                if(count>0){
                    tasksRemaining=true;
                    break;
                }
            }

            if (tasksRemaining) {
                // Full cycle is needed, including idle intervals
                // time += n+1;

                // because the whole cycle is counted.
                time += n + 1;
            } else {
                // Last cycle needs only the actually executed intervals

                //because the last cycle doesn't need idle slots.
                time += executed;
            }
        }
        return time;
    }
};