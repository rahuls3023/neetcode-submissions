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

            int difference=0;

            if(x==y){
                difference=x-y;
            }
            else if(x!=y){
                difference=abs(x-y);
            }
            if(difference>0){
                pq.push(difference);
            }
        }
        return pq.top();
    }
};
