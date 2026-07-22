class Solution {
public://using max heap
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(auto it:stones){
            pq.push(it);
        }

        while(pq.size()>1){
            int x=pq.top();
            pq.pop();

            int y=pq.top();
            pq.pop();

            int difference=x-y;

            if(difference>0){
                pq.push(difference);
            }
        }
        if(pq.empty()) return 0;
        else return pq.top();
    }
};
