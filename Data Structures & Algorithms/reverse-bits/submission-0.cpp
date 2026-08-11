class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n==0) return 0;

        int result=0;
        for(int i=1;i<=32;i++){

            //left shift kro result ko, new bit ke lie jagah bnao
            result<<=1;

            //add kro bit at last position in result using OR
            result=(result|(n&1));

            //right shift kro n ka ek lsb last bit discard krdo
            n>>=1;
        }
        return result;
    }
};
