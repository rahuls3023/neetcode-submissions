class Solution {
public://approach-1> finding first and last occurence of character
    int countPalindromicSubsequence(string s) {
        // So kisi bhi character a ke liye:

        // uska first occurrence lo
        // uska last occurrence lo
        // in dono ke beech jitne unique characters hain, utne a b a palindromes banenge.

        int ans=0;

        for(char ch='a';ch<='z';ch++){
            int first=s.find(ch);
            int last=s.rfind(ch);

            if(first==string::npos || first==last){
                //character exist nhi krta ya fir character ka occurence single h.
                continue;
            }

            //ab unique characters chaiye between first and last occurence of ch.

            unordered_set<char>st;

            for (int i = first + 1; i < last; i++) {//outer element ko middle nhi bnana
                st.insert(s[i]);
            }
            ans+=st.size();
        }
        return ans;
    }
};