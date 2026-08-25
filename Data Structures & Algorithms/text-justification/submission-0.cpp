class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>currentline;
        int currentlineTotalchars=0;

        for(int i=0;i<words.size();i++){
            string &currentword=words[i];
            int currentlineneedednumberofspaces=currentline.size();

        if(currentlineTotalchars+currentlineneedednumberofspaces+currentword.size()>maxWidth ){
             int extraspaces=maxWidth-currentlineTotalchars;
             int spacesgoinbetweenwords=extraspaces/max(1,(int)(currentline.size()-1));

             int remainder=extraspaces%max(1,(int)(currentline.size()-1));

             for(int j=0;j<currentline.size()-1;j++){
                //add even spaces
                for(int k=0;k<spacesgoinbetweenwords;k++){
                     currentline[j]+=" ";
                }
                     if(remainder>0){
                        currentline[j]+=" ";
                        remainder--;
                }
             }
             if(currentline.size()==1){
                while(extraspaces--)
                currentline[0]+=" ";
             }
             string finalline="";
             for(string wordwithspaces : currentline){
                finalline+=wordwithspaces;
             }
             ans.push_back(finalline);
             currentline.clear();
             currentlineTotalchars=0;
           }
            currentline.push_back(currentword);
            currentlineTotalchars+= currentword.size();
        }
        string finalline="";
        for(auto word:currentline)
           finalline+=word+" ";

           finalline.pop_back();

           int leftspaces=maxWidth-finalline.size();
           while(leftspaces--)
            finalline+=" ";
           ans.push_back(finalline);
        return ans;
    }
};