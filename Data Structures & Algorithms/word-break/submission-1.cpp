class Solution {
public:
    int n;
    bool memoisation(int index,string &s,unordered_set<string>&st,vector<int>&dp){
        //base case
        if(index==n){
            //match karte-karte string ke last index tak pahunch gaye,
            //iska matlab poori string valid words me break ho gayi
            return true;
        }

        if(st.find(s)!=st.end()){
            return true;
        }

        // dp[index] = kya string ka index se n-1 tak wala remaining part dictionary ke valid words me break ho sakta hai ya nahi

        if(dp[index]!=-1) return dp[index];

        //current index se har possible length ki substring banayenge:
        //length 1, 2, 3, ... n tak
        //aur check karenge ki jo substring bani hai vo set me present hai ya nahi

        for(int len=1;len<=s.size();len++){
            string curr=s.substr(index,len);

            if(st.find(curr)!=st.end() && memoisation(index+len,s,st,dp)){
                //current index se length 'len' ka word dictionary me mil gaya,
                //ab us word ke baad wali remaining string ke liye next index = index + len hoga
                return dp[index]= true;
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        n=s.size();

        //dictionary ke saare words set me store kar rahe hain
        //taaki words ko efficiently search kar sakein
        for(auto word:wordDict){
            st.insert(word);
        }

        //string ko index 0 se break karna start karenge
        vector<int>dp(n+1,-1);
        return memoisation(0,s,st,dp);
    }
};