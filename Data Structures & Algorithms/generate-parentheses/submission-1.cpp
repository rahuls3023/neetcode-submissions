class Solution {
public://approach-2>using open and close
    vector<string>ans;

    void solve(string &curr,int n,int open,int close){
        //base case
        if(curr.length()==2*n){
                ans.push_back(curr);
            return;
        }

        //ek baar "(" leke dekhege
        //for a valid parantheses , open ka count hamesha <n hota hai kyuki valid parantheses me open and close dono ka count ==n hota h tbhi total 2n banta h valid pair.
        if(open<n){
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
        }
         
         //ek baar ")" leke dekhege
         //valid parantheses me kbhi bhi close ka count, open se jyada nhi hoga agar horha h to us string ko nhi lege aage .
         if(close<open){
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
         }   
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n,0,0);
        return ans;
    }
};