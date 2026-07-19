class Solution {
public://generate all substrings
    bool isValid(unordered_map<char,int>&tfreq,unordered_map<char,int>&currentWindow){
        //check required freq of every t character

        for(auto it:tfreq){
            char ch=it.first;
            auto freq=it.second;

            if(currentWindow[ch]<freq) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.size();

        unordered_map<char,int>tfreq;

        for(auto it:t){
            tfreq[it]++;
        }

        int startIndex=-1;
        int minlen = INT_MAX;

        for(int i=0;i<n;i++){
            unordered_map<char,int>currentWindowfreq;
            for(int j=i;j<n;j++){
                currentWindowfreq[s[j]]++;

                if(isValid(tfreq,currentWindowfreq)){
                    //valid substring milgya 
                    int length=j-i+1;

                    if(length<minlen){
                        minlen=length;
                        startIndex=i;
                    }
                    break;
                }
            }
        }
        if(startIndex==-1){
            return "";
        }
        return s.substr(startIndex,minlen);
    }
};
