class Solution {
public://approac-1> counting bits for every number with naive counting approach
    int countbits(int n){
        int count=0;
        while(n!=0){
            if(n&1){
                count++;
            }
            n=n>>1;
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
