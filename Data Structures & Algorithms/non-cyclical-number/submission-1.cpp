class Solution {
public://method-2>  Floyd's Cycle Finding Algorithm- > without extra space
//use it to detect cycle if any
    int squaredDigits(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum+=digit*digit;
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        //O(logn),O(1)

        int slow=squaredDigits(n);
        int fast=squaredDigits(squaredDigits(n));

        while(slow!=fast){
            //slow moves one step
            slow=squaredDigits(slow);

            //fast moves 2 step
            fast=squaredDigits(squaredDigits(fast));
        }

        if(slow==1)return true;
        else return false;
    }
};