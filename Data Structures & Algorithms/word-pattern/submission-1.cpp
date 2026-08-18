class Solution {
public://approach-2> using map and set
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string>words;
        string word;


        int n=pattern.length();

         // string ko words me split kro
        while(ss >> word){
            words.push_back(word);
        }

        // characters aur words ki count same honi chahiye
        if(pattern.size() != words.size()){
            return false;
        }

        unordered_map<char,string>mp;
        unordered_set<string>used;

         for(int i=0;i<pattern.size();i++){

            char ch = pattern[i];
            string currentWord = words[i];

            //dono new h to create mapping
            if(mp.find(ch)==mp.end() && used.find(currentWord)==used.end()){
                mp[ch]=currentWord;
                used.insert(currentWord);
            }

            //character already mapped h
            else if(mp.find(ch)!=mp.end()){
                if(mp[ch]!=currentWord){
                    return false;
                }
            }
            //character new h but word already kisi aur character ke saath used h
            else{
                return false;
            }
        }
        return true;
    }
};