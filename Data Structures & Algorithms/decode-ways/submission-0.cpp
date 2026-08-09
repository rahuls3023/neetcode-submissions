class Solution {
public://recursion
    int recursion(int index,string &s){
        //base case
        if(index==s.length()) return 1;//1 valid string decode hogyi

        if(s[index]=='0') return 0;//cannot be mapped

        //we can choose the characters in group of 1 or in 2

        int takeOne=0;
        takeOne+=recursion(index+1,s);

        //choose two characters and check if it lies between 10 and 26
        int takeTwo=0;
        if(index+1<s.length()){
            int number=(s[index]-'0')*10+(s[index+1]-'0');

            if(number>=10 && number<=26){
                takeTwo+=recursion(index+2,s);
            }
        }
        

        return (takeOne+takeTwo);
    }
    int numDecodings(string s) {
        return recursion(0,s);
    }
};