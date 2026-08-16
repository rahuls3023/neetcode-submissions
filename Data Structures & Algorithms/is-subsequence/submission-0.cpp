class Solution {
public://brute force
    bool recursion(string &s,string &t,int index,string current){
        if(index==t.size()){
            if(current==s) return true;
            else return false;
        }

        //take
        if(recursion(s,t,index+1,current+t[index])){
            return true;
        }

        //not-take
        if(recursion(s,t,index+1,current)){
            return true;
        }
        return false;
    }
    bool isSubsequence(string s, string t) {
        return recursion(s,t,0,"");
    }
};