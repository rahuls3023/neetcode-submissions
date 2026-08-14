class Solution {
public:
    int recursion(int index,vector<int>&stoneValue){
        if(index>=stoneValue.size()) return 0;

        int total=0;
        int best=INT_MIN;

        for(int take=1;take<=3;take++){

            if(index+take-1>=stoneValue.size())break;

            total+=stoneValue[index+take-1];

            best=max(best,total-recursion(index+take,stoneValue));
        }
        return best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int diff=recursion(0,stoneValue);

        if(diff>0){
            return "Alice";
        }
        else if(diff==0){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};