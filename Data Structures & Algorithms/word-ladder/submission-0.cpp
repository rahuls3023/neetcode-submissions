class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // {current word, number of words in transformation sequence}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        // beginWord is already being processed,
        // so remove it to avoid revisiting
        st.erase(beginWord);

        while(!q.empty()) {

            auto frontPair = q.front();
            q.pop();

            string frontString = frontPair.first;
            int sequenceLength = frontPair.second;

            // if endWord is reached,
            // return number of words in the sequence
            if(frontString == endWord) {
                return sequenceLength;
            }

            // try changing each character one by one
            for(int index = 0; index < frontString.length(); index++) {

                // preserve original character
                char originalCharacter = frontString[index];

                // try replacing it with every character from 'a' to 'z'
                for(char ch = 'a'; ch <= 'z'; ch++) {

                    frontString[index] = ch;

                    // if newly formed word exists,
                    // it is a valid transformation
                    if(st.find(frontString) != st.end()) {

                        // add next word with sequence length + 1
                        q.push({frontString, sequenceLength + 1});

                        // remove immediately to mark it as visited
                        st.erase(frontString);
                    }
                }

                // restore original character
                // before moving to the next index
                frontString[index] = originalCharacter;
            }
        }

        // no valid transformation sequence exists
        return 0;
    }
};