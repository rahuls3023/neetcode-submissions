class Solution {
public://approach-1>
    vector<string>ans;

    bool isValid(string &curr){
        int count=0;

        for(int i=0;i<curr.length();i++){
            if(curr[i]=='(') count++;
            else count--;
            if(count<0) return false;
        }
        if(count==0) return true;
        else return false;
    }
    void solve(string &curr,int n){
        //base case
        if(curr.length()==2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }

        //ek baar "(" leke dekhege
         curr.push_back('(');
         solve(curr,n);
         curr.pop_back();

         //ek baar ")" leke dekhege
         curr.push_back(')');
         solve(curr,n);
         curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return ans;
    }
};