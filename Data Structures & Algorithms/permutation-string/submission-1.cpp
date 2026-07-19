class Solution {
public://optimal approach-> sliding window
    bool checkInclusion(string s1, string s2) {

        if(s1.size()>s2.size()) return false;

        unordered_map<char,int>string1;
        unordered_map<char,int>window;//iska use krege jab loop me s2 pe traverse krege

        for(auto it:s1){
            string1[it]++;
        }

        int left=0;
        
        for(int right=0;right<s2.size();right++){

            window[s2[right]]++;

            //window size maintain kro
            if(right-left+1>s1.size()){
                window[s2[left]]--;


                // Optional cleanup
                if (window[s2[left]] == 0) {
                    window.erase(s2[left]);
                }

                left++;
            }
             // When window size is exactly m, compare frequencies
            if (right - left + 1 == s1.size() && window == string1) {
                return true;
            }
        }
        return false;
    }
};
