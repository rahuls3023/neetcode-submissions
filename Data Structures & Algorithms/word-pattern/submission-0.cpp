class Solution {
public://approach-1> using 2 maps
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string>words;
        string word;

        //s ko words me convert kro
        while(ss>>word){
            words.push_back(word);
        }

        //agar dono ka size same nhi h to
        if(pattern.size()!=words.size()) return false;

        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;

        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            string word=words[i];

            //character pehle se mapped h
            if(mp1.count(ch) && mp1[ch]!=word){
                return false;
            }
            
            //word pehle se mapped h
            if(mp2.count(word) && mp2[word]!=ch){
                return false;
            }
            mp1[ch]=word;
            mp2[word]=ch;
        }
        return true;
    }
};