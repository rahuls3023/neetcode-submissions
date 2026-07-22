class Solution {
public:
    // Optimal Approach 2 -> Iterative Binary Exponentiation
    double myPow(double x, int n) {
        long long power = n;
        double ans = 1;

        // If power is negative:
        // x^(-n) = (1/x)^n
        if (power < 0) {
            power = -power;   // Make the power positive
            x = 1 / x;         // Invert the base
        }

        while (power > 0) {

            // If current power is odd,
            // include the current base in the answer.
            if (power % 2 != 0) {
                ans *= x;
            }

            // Square the base for the next iteration.
            // Example: 2 -> 4 -> 16 -> 256 ...
            x *= x;

            // Since the base is squared, halve the power.
            // Example: 13 -> 6 -> 3 -> 1 -> 0
            power /= 2;
        }

        return ans;
    }
};