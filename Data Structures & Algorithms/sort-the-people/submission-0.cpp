class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string>mp;

        for(int i=0;i<names.size();i++){
            mp[heights[i]]=names[i];
        }   

        sort(heights.begin(),heights.end(),greater<int>());

        vector<string>ans;

        //sorted heights ko according name nikalo
        for(int it:heights){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};