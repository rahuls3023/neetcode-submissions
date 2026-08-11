class Solution {
public://approac-2> counting bits for every number with---> Brian Kernighan's Algorithm
    int countbits(int n){
        int count=0;
        while(n!=0){
            n=n&(n-1);//remove rightmost set bit
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans;

        for(int i=0;i<=n;i++){
            int bitsForCurrent=countbits(i);
            ans.push_back(bitsForCurrent);
        }
        return ans;
    }
};
