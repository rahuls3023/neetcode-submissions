class Solution {
public://optimal approach-> sliding window
    int characterReplacement(string s, int k) {
        int n=s.size();

        vector<int>freq(26,0);
        int maxLen=0;
        int left=0;
        int maxFreq=0;

        for(int right=0;right<n;right++){
            freq[s[right]-'A']++;

            maxFreq=max(maxFreq,freq[s[right]-'A']);

            int windowLength=right-left+1;

            int changesNeeded=windowLength-maxFreq;

            //shrink invalid window
            while(changesNeeded>k){
                freq[s[left]-'A']--;
                left++;

                windowLength=right-left+1;
                changesNeeded = windowLength - maxFreq;
            }
            
             if(changesNeeded<=k){
                maxLen=max(maxLen,windowLength);
            }
        }
        return maxLen;
    }
};
