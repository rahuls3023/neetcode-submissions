class Solution {
public://brute force-> using sorting
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        while(stones.size()>1){
            sort(stones.begin(),stones.end());

            int x=stones.back();
            stones.pop_back();

            int y=stones.back();
            stones.pop_back();

            int difference=x-y;

            if(difference>0){
                stones.push_back(difference);
            }
        }

        if(stones.size()==0) return 0;
        else return stones.back();
    }
};
