class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded="";
        
        for(auto word:strs){
            //pehle string ki length store kro
            int len=word.size();
            encoded+=to_string(len);

              //length aur actual string ke bich delimeter
            encoded+="#";

            //ab delimeter ke baad word add kro
            encoded+=word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>result;

        int i=0;
        int n=s.size();

        while(i<n){
            //current string ki length ke baad delimeter "#" find kro

            int delimeterIndex=s.find("#",i);//ye btayega startindex of delimeter

            //length ko string se integer me convert kro
            int wordLength=stoi(s.substr(i,delimeterIndex-i));//delimter se pehle hi to hoga length bhi jo ki characgter type me tha pehle

            //"#" ke baad actual string start h
            int stringStart=delimeterIndex+1;
            string word=s.substr(stringStart,wordLength);

            result.push_back(word);

             // Next encoded portion par move karo
            i = stringStart + wordLength;
        }
        return result;
    }
};
