class Solution {
public://approach-1> O(N^2)
    bool checkPrime(int num){
        int cnt=0;

        for(int i=1;i<=num;i++){
            if(num%i==0) cnt++;
        }
        if(cnt==2) return true;
        else return false;
    }
    int countPrimes(int n) {
        int count=0;

        for(int i=2;i<=n;i++){
            if(checkPrime(i)){
                count++;
            }
        }
        return count;
    }
};