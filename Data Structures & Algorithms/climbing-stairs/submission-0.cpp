class Solution {
public:
    int recursion(int n){
        //base case
        if(n==0) return 1;
        if(n<0) return 0;

        //take 1 step
        int oneStep=0;
        oneStep+=recursion(n-1);

        //take 2 step
        int twoStep=0;
        twoStep+=recursion(n-2);

        return oneStep+twoStep;
    }
    int climbStairs(int n) {
        return recursion(n);
    }
};