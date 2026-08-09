class Solution {
public:
    int n;
    bool recursion(int index,string &s,unordered_set<string>&st){
        //base case
        if(index==n){
            //match karte-karte string ke last index tak pahunch gaye,
            //iska matlab poori string valid words me break ho gayi
            return true;
        }

        if(st.find(s)!=st.end()){
            return true;
        }

        //current index se har possible length ki substring banayenge:
        //length 1, 2, 3, ... n tak
        //aur check karenge ki jo substring bani hai vo set me present hai ya nahi

        for(int len=1;len<=s.size();len++){
            string curr=s.substr(index,len);

            if(st.find(curr)!=st.end() && recursion(index+len,s,st)){
                //current index se length 'len' ka word dictionary me mil gaya,
                //ab us word ke baad wali remaining string ke liye next index = index + len hoga
                return true;
            }
        }
        return false;
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
        return recursion(0,s,st);
    }
};