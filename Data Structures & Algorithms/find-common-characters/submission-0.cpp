class Solution {
public: // frequency counting
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, INT_MAX);

        for (string &word : words) {
            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            // take minimum frequency
            for (int i = 0; i < 26; i++) {
                common[i] = min(common[i], freq[i]);
            }
        }

        vector<string> ans;

        for (int i = 0; i < 26; i++) {
            // add common characters
            while (common[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                common[i]--;
            }
        }

        return ans;
    }
};
