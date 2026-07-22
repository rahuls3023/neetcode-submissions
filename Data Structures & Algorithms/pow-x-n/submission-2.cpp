class Solution {
public://optimal-> recursive binary exponentiation
    double solve(double x,int n){
        if(n==0) return 1;
        //for negative power
        if(n<0){
            return solve(1/x,-n);
        }
        //for even power
        if(n%2==0){
            return solve(x*x,n/2);
        }
        //for odd power
        return x*solve(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x,n);
    }
};
