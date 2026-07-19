class Solution {
public:
    // Optimal approach -> Sliding Window
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int n = s.size();

        unordered_map<char, int> tfreq;

        // Store how many times each character of t is required
        for (auto it : t) {
            tfreq[it]++;
        }

        int startIndex = -1;
        int minLen = INT_MAX;

        // Total number of characters still required
        int required = t.size();

        int left = 0;

        for (int right = 0; right < n; right++) {

            char ch = s[right];

            // If this character is still required,
            // one required character has been fulfilled
            if (tfreq[ch] > 0) {
                required--;
            }

            // Include current character in the window
            tfreq[ch]--;

            // If required becomes 0,
            // current window contains all characters of t
            while (required == 0) {

                int currentLength = right - left + 1;

                // Update minimum valid window
                if (currentLength < minLen) {
                    minLen = currentLength;
                    startIndex = left;
                }

                char leftChar = s[left];

                // Remove left character from the window
                tfreq[leftChar]++;

                // If frequency becomes positive,
                // this character is required again
                if (tfreq[leftChar] > 0) {
                    required++;
                }

                // Shrink window from the left
                left++;
            }
        }

        // No valid window found
        if (startIndex == -1) {
            return "";
        }

        return s.substr(startIndex, minLen);
    }
};