class Solution {
public:
    int recursion(int i,int j,string &word1,string &word2){
        //agar word1 jldi khtm hojaye
        //word 2 ke baaki characters insert hi krne pdege
        if(i>=word1.size()){
            return word2.size()-j;
        }

        //if word2 finishes early
        //delete remaining characters from word1
        if(j>=word2.size()){
            return word1.size()-i;
        }

        if(word1[i]==word2[j]){
            return recursion(i+1,j+1,word1,word2);
        }
        else{
            //we have 3 cases
            
            //agar word1 me character replace from from word2
            int replace=1+recursion(i+1,j+1,word1,word2);

            //agar word1 ka character delete krdia
            int deleteIt=1+recursion(i+1,j,word1,word2);
            
            //agar word1 me insert krdia current character from word 2
            //because abhi original jo match krna tha word1 ka char wo match hona bcha h
            int insert=1+recursion(i,j+1,word1,word2); 

            return min({replace,deleteIt,insert});
        }
    }

    int minDistance(string word1, string word2) {
        return recursion(0,0,word1,word2);
    }
};