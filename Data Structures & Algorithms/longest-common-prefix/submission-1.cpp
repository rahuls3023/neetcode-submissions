class Solution {
public://y O(n log n * L)
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();

        if(strs.empty()) return "";

        string ans="";

        sort(begin(strs),end(strs));

        string first=strs[0];

        string last=strs[n-1];

        int minLength=min(first.length(),last.length());

        for(int i=0;i<minLength;i++){
            if(first[i]!=last[i])break;

            ans+=first[i];
        }
        return ans;
    }
};