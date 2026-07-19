class Solution {
public://optimal-> 2 pointer
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;

        while(left<right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else{
                 if(tolower(s[left])!=tolower(s[right])) return false;
                left++;
                right--;
            }
        }
        return true;
    }
};
