class Solution {
public:
    bool recursion(string &s, string &p,int i,int j){
        if(i==s.size() && j==p.size()){
            return true;
        }

        if(i!=s.size() && j==p.size()) return false;

        // check current character match
        bool currMatch=(i<s.length()) && (p[j]=='.' || s[i]==p[j]);

        //if next character is'*'
        if(j+1<p.length() && p[j+1]=='*'){
            //char* -> mtlb previous character 0 or more times aa skta h

             // choice 1 -> use char* 0 times, so skip both char and '*'
            // choice 2 -> use current char once and stay at same pattern index
            return recursion(s,p,i,j+2) || recursion(s,p,i+1,j);
        }

         // normal match without '*'
        if(currMatch==true) {
            return recursion(s, p, i + 1, j + 1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return recursion(s,p,0,0);
    }
};