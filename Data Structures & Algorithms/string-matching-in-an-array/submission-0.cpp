class Solution {
public://brute force
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n=words.size();

        //check for every ith string if it is substring of jth string or not
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i==j) continue;//dont compare samw word with each other

                //check whether words[i] is substring of words[j]
                if(words[j].find(words[i])!=string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};