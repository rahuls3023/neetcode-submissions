class Solution {
public://recursion
    bool isPalindrome(int left,int right,string &s){

        if(left>=right) return true;

        if(s[left]==s[right]){
            return isPalindrome(left+1,right-1,s);
        }

        return false;

    }
    int countSubstrings(string s) {
        int n=s.size();

        int totalPalindrome=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    totalPalindrome+=1;
                }
            }
        }
        return totalPalindrome;
    }
};