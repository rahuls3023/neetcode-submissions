class Solution {
public://brute force
    int strStr(string haystack, string needle) {
       for(int i=0;i<haystack.size();i++){
            string temp="";

            for(int j=i;j<haystack.size();j++){
                temp+=haystack[j];

                if(temp==needle){
                    return i;
                }
            }
       }
       return -1;
    }
};