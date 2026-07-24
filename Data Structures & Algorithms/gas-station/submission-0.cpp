class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int deficit = 0;
        int balance = 0;

        for(int i = 0; i < gas.size(); i++) {
            // Current gas left after reaching the next station
            balance = balance - cost[i] + gas[i];

            if(balance < 0) {
                // We cannot reach the next station from the current start.
                // So, no station between 'start' and 'i' can be a valid answer.
                deficit += abs(balance);   // Gas shortage accumulated so far
                start = i + 1;             // Try the next station as the new starting point
                balance = 0;               // Restart journey with 0 gas
            }
        }

        // If the remaining balance can cover the total deficit,
        // then completing the entire circle is possible.
        if(balance - deficit >= 0) {
            return start;
        }

        return -1;
    }
};