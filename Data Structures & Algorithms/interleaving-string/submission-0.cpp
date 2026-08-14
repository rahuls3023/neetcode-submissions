class Solution {
public:
    bool recursion(string &s1,string &s2,string &s3,int i,int j,int k){
        //base case
        if(k==s3.size()){
            if(i==s1.size() && j==s2.size()) return true;
            else return false;
        }

        //choose or not choose
        bool ans=false;

        //take s1 character
        if(i<s1.size() && s1[i]==s3[k]){
            ans=ans | recursion(s1,s2,s3,i+1,j,k+1);
        }

        //take s2 character
        if(j<s2.size() && s2[j]==s3[k]){
            ans = ans | recursion(s1,s2,s3,i,j+1,k+1);
        }
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;

        return recursion(s1,s2,s3,0,0,0);
    }
};