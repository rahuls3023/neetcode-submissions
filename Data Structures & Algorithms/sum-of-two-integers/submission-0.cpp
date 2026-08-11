class Solution {
public: // bit manipulation -> xor + carry
    int getSum(int a, int b) {

        while(b != 0) {
            int sum = a ^ b;           // addition without carry
            int carry = (a & b) << 1;  // calculate carry

            a = sum;
            b = carry;
        }

        return a;
    }
};