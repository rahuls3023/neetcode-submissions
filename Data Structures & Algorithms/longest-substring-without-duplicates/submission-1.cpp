class Solution {
public:
    // Optimal Approach -> Sliding Window + Frequency Map
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxLength = 0;

        unordered_map<char, int> mp; // stores frequency of characters in current window

        for (int right = 0; right < n; right++) {

            // Include the current character in the window
            mp[s[right]]++;

            // Shrink the window until it contains unique characters
            while (mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }

            // Update the maximum length of a valid window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};