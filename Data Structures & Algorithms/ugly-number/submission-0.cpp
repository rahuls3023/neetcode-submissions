class Solution {
public:
    bool isUgly(int n) {
        //ugly number should pe positive
        if(n<=0) return false;

        //2 ke saare factor remove kro
        while(n%2==0){
            n=n/2;
        }

        //3 ke saare factor remove kro
        while(n%3==0){
            n=n/3;
        }

        //5 ke saare factor remove kro
        while(n%5==0){
            n=n/5;
        }

        //agar koi aur prime factor nahi bacha
        return n==1;
    }
};