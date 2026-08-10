class Solution {
    typedef pair<int,int>P;
public://prim's algo.
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        vector<vector<P>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 //jab i->j ke lie paring kargee tbhi j->i ke lie bhi kr lege
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int d=abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,d});//i-> j ka distance=d;
                adj[j].push_back({i,d});
            }
        }

        //step-2> bass ek baar adjlist is created, apply prim's algo
        priority_queue<P,vector<P>,greater<P>>pq;

        pq.push({0,0});//{wt,node};
        vector<bool>inMST(n,false);
        int sum=0;

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int wt=curr.first;
            int node=curr.second;

            if(inMST[node]==true) continue;

            inMST[node]=true;
            sum+=wt;

            for(auto &nbr:adj[node]){
                int nbrNode=nbr.first;
                int nbrwt=nbr.second;

                if(inMST[nbrNode]==false){
                    pq.push({nbrwt,nbrNode});
                }
            }
        }
        return sum;
    }
};