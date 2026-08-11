class Solution {
public:// brian kernighan's algorithm
    int hammingWeight(uint32_t n) {
        int count=0;

        while(n!=0){
            n=n&(n-1);//remove rightmost one bit
            count++;
        }
        return count;
    }
};
