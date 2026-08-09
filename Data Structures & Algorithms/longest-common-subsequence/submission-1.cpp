class Solution {
public:
    int recursion(int i,int j,string text1,string text2){

        if(i<0 || i>=text1.size() || j<0 || j>=text2.size()) return 0;

        if(text1[i]==text2[j]){
            return 1+recursion(i+1,j+1,text1,text2);
        }else{
            //we have two choices
            //either we can match for ith character by increasing j or we can match jth character by increasin i.
            return max(recursion(i+1,j,text1,text2),recursion(i,j+1,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        return recursion(0,0,text1,text2);
    }
};