class Solution {
public://brute force-> iterative
    double myPow(double x, int n) {
       double ans=1;

         for (long long i = 0; i < abs(n); i++) {
            ans *= x;
        }
        if(n<0){
            return 1.0/ans;
        }
        return ans;
    }
};
