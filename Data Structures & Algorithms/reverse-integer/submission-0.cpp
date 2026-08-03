class Solution {
public:
    int reverse(int x) {
        int sign=1;

       long long num=x;

        if(x<0){
            sign=-1;
            num=-num;
        }

         long long reverseNum=0;

         while(num>0){
            int digit=num%10;
            reverseNum=reverseNum*10+digit;
            num=num/10;
         }

         reverseNum*=sign;

          // Check if answer fits in int range
        if (reverseNum > INT_MAX || reverseNum < INT_MIN)
            return 0;

        return (int)reverseNum;
    }
};
