class Solution {
public://brute force
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=INT_MIN;

        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int maxFreq=0;

            for(int j=i;j<n;j++){
                freq[s[j]-'A']++;

                maxFreq=max(maxFreq,freq[s[j]-'A']);

                int currentLength=j-i+1;

                int changesNeeded=currentLength-maxFreq;

                if(changesNeeded<=k){
                    maxLen=max(maxLen,currentLength);
                }
            }
        }
        return maxLen;
    }
};
