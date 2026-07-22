class Solution {
public://optimal-> max heap
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;//{distance,points}

        for(int i=0;i<points.size();i++){
            int pointX=points[i][0];
            int pointY=points[i][1];

            // int originX=0;
            // int originY=0;

            int distance=pointX*pointX+pointY*pointY;

           pq.push({distance, {pointX, pointY}});

            if(pq.size()>k){
                pq.pop();
            } 
        }

        vector<vector<int>>ans;

        while(!pq.empty()){
            auto distance=pq.top().first;
            int pointX=pq.top().second.first;
            int pointY=pq.top().second.second;

            pq.pop();
            
            ans.push_back({pointX,pointY});
        }
        return ans;
    }
};