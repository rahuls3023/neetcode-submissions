class Solution {
public://approach-2> using freq array
    int heightChecker(vector<int>& heights) {
        vector<int>freq(101,0);

        for(int height:heights){
            freq[height]++;
        }

        int index=0;
        int count=0;

        //expected sorted order generate kro
        for(int height=1;height<=100;height++){
            while(freq[height]>0){
                if(heights[index]!=height){
                    count++;
                }
                index++;
                freq[height]--;
            }
        }
        return count;
    }
};