class Solution {
public://brute force-> sorting
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,pair<int,int>>>vec;

        for(int i=0;i<points.size();i++){
            int pointX=points[i][0];
            int pointY=points[i][1];

            int distance=pointX*pointX+pointY*pointY;

            vec.push_back({distance,{pointX,pointY}});
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>>ans;
        int i=0;
        while(k--){
            ans.push_back({vec[i].second.first,vec[i].second.second});
            i++;
        }
        return ans;
    }
};