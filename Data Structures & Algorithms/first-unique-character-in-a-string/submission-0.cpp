class Solution {
public://approach-1> sorting
    int firstUniqChar(string s) {
        vector<pair<char,int>>V;

        for(int i=0;i<s.size();i++){
            V.push_back({s[i],i});
        }
        sort(begin(V),end(V));

        int ans=s.size();

        for(int i=0;i<V.size()-1;i++){
           // unique character
            if ((i == 0 || V[i].first != V[i - 1].first) &&
                (i == V.size() - 1 || V[i].first != V[i + 1].first)) {
                
                ans = min(ans, V[i].second);
            }
        }
        if(ans==s.size()) return -1;
        else return ans;
    }
};