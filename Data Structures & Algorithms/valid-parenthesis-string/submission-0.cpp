class Solution {
public://recursion
    bool solve(int i,int open,string &s){
        if(i==s.size()){
            if(open==0){
                return true;
            }
            else return false;
        }

        bool isValid=false;
        if(s[i]=='('){
            isValid=isValid | solve(i+1,open+1,s);
        }
        else if(s[i]=='*'){
            //check for all 3
            //ek ek baar 3ino leke dekho

            isValid=isValid | solve(i+1,open+1,s);//agar * ko ( lete hai to
            isValid=isValid | solve(i+1,open,s);//agar "" lete h * ko
            if(open>0){
                isValid=isValid | solve(i+1,open-1,s);//agar * ko ) lete h
            }
        }
        else  if(s[i]==')'){
            // ')' milgya
            //open count atleast > 0 hona chaiye

            if(open>0){
                isValid|=solve(i+1,open-1,s); 
            }
        }
        return isValid;
    }
    bool checkValidString(string s) {
        int open=0;
        return solve(0,open,s);
    }
};