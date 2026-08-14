class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;

        for(char ch:s){
            mp[ch]++;
        }

        int length=0;
        bool odd=false;

        for(auto &it:mp){
            int freq=it.second;

            //even frequency can be used completely
            if(freq%2==0){
                length+=freq;
            }
            else{
                //for odd frequency, use the even part
                length+=freq-1;
                odd=true;
            }
        }

        //one odd character can be placed at the center
        if(odd){
            length++;
        }

        return length;
    }
};