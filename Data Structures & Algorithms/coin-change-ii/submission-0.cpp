class Solution {
public:
    int recursion(int index,int amount,vector<int>&coins){
        if(amount==0){
            return 1;
        }
        if(index>=coins.size()){
            return 0;
        }

        int take=0;
        if(coins[index]<=amount){
            take+=recursion(index,amount-coins[index],coins);
        }
        int not_take=recursion(index+1,amount,coins);

        return (take+not_take);
    }

    int change(int amount, vector<int>& coins) {
        return recursion(0,amount,coins);
    }
};