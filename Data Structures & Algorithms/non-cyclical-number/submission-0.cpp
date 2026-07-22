class Solution {
public:
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
        if(n==1) return true;

        unordered_set<int>st;

        while(n!=1){
            if(st.count(n)){
                // Number already seen before, so we have entered a cycle.
                // Since we reached a cycle before reaching 1, it is not a happy number.
                return false;
            }
            st.insert(n);

            n=squaredDigits(n);
        }
        return true;
    }
};