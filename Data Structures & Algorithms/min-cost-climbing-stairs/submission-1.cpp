class Solution {
public:
    int recursion(int index,vector<int>&cost){
        if(index>=cost.size()){
            return 0;
        }
        //either 1 step or 2 step
        int oneStep=0;
        oneStep+=cost[index]+recursion(index+1,cost);

        int twoStep=0;
        twoStep+=cost[index]+recursion(index+2,cost);

        return min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int startFromIndex0=recursion(0,cost);

        int startFromIndex1=recursion(1,cost);

        return min(startFromIndex0,startFromIndex1);
    }
};