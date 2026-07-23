class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string &s,int idx,vector<string>&curr,vector<vector<string>>&ans){
        if(idx>=s.length()){
            ans.push_back(curr);
            return;
        }

        for(int j=idx;j<s.length();j++){
            //hum idx .... i ke bich ka parition le rhe hai baar baar and check kr rhe h palindrome h ya nhi
            if(isPalindrome(s,idx,j)){
                curr.push_back(s.substr(idx,j-idx+1));

                solve(s,j+1,curr,ans);//next partition choose kro

                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;

        solve(s,0,curr,ans);
        return ans;
    }
};