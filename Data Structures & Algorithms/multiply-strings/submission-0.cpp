class Solution {
public: // Optimal approach
    string multiply(string num1, string num2) {

        // If either number is 0, the product will always be 0.
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.size();
        int n = num2.size();

        // The product of an m-digit number and an n-digit number
        // can have at most (m + n) digits.
        vector<int> ans(m + n, 0);

        // Multiply every digit of num1 with every digit of num2,
        // starting from the last digit (just like school multiplication).
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int product = digit1 * digit2;

                // The current digit of the product is stored here.
                int digitPosition = i + j + 1;

                // The carry generated from the product is added
                // one position to the left.
                int carryPosition = i + j;

                // Add the current product to any value that is
                // already present at this position.
                int sum = ans[digitPosition] + product;

                // Store the last digit at the current position.
                ans[digitPosition] = sum % 10;

                // Add the carry to the left position.
                // We use += because this position may already
                // contain carry from previous multiplications.
                ans[carryPosition] += sum / 10;
            }
        }

        string result = "";

        // Skip unnecessary leading zeroes.
        int i = 0;
        while (i < ans.size() && ans[i] == 0) {
            i++;
        }

        // Convert the digits stored in the vector into a string.
        while (i < ans.size()) {
            result.push_back(ans[i] + '0');
            i++;
        }

        return result;
    }
};