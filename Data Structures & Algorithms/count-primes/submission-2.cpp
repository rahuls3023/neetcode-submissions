class Solution {
public://approach-2> better approach O(n√n)
    bool checkPrime(int num){
        if(num<2) return false;

        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int count=0;

        for(int i=2;i<n;i++){
            if(checkPrime(i)){
                count++;
            }
        }
        return count;
    }
};