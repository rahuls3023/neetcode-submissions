class Solution {
public://optimal-> expand around center
    int expandAroundCenter(string &s,int left,int right){
        int count=0;

        while(left>=0 && right<s.size() && s[left]==s[right]){
            //har baar ye loop chalne pe ek palindromic substring miil rha h
            count++;

            left--;

            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.size();

        int total=0;

         for(int i=0;i<n;i++){
            //agar even length hai

           total+= expandAroundCenter(s,i,i+1);

            //agar odd length

           total+= expandAroundCenter(s,i,i);
        }


        return total;
    }
};