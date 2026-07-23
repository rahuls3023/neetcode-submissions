class Solution {
public:
    vector<string> ans;

    void solve(string &digits, int index, string &curr, unordered_map<char,string> &mp) {

        // Base case: saare digits process ho chuke hain
        if(index == digits.size()) {
            // Empty input ("") ke case me empty string answer me nahi dalni
            if(curr.length() > 0) {
                ans.push_back(curr);
            }
            return;
        }

        // Current digit ke corresponding letters nikalo
        char digit = digits[index];
        string mappedString = mp[digit];

        // Current digit ke har possible letter ko try karo
        for(int j = 0; j < mappedString.size(); j++) {

            // Har recursive call me current digit ke saare letters
            // start se try karne hain (a,b,c... ya d,e,f...)
            curr.push_back(mappedString[j]);

            // Next digit process karo
            solve(digits, index + 1, curr, mp);

            // Dusra letter try karne ke liye backtrack
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string curr = "";
        solve(digits, 0, curr, mp);

        return ans;
    }
};