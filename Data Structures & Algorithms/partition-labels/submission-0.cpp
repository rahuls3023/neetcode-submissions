class Solution {
public://using hashmap
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastIndex;//ye store krega lastIndex occurence of all characters

        for(int i=0;i<s.length();i++){
            lastIndex[s[i]]=i;
        }

        int i=0;
        int j=0;
        vector<int>ans;
        while(j<s.length()){
            int currentMaximumRange=lastIndex[s[j]];//current range atleast current character ke last index tk to hona hi chaiye uske bich me agar koi character ka range  usse jyada milgya to update krte rhege

            //check kro all characters in that range, agar maximum ranhe update hoti h to kro
            while(j<=currentMaximumRange){
                    currentMaximumRange=max(lastIndex[s[j]],currentMaximumRange);
                    j++;
            }
            //we have reached the last index of the maximum range that is possible, so that each letter appears in at most in one part.

            int partSize=j-i;

            ans.push_back(partSize);

            i=j;//not j+1 kyuki j already currrent maximum range ke +1 pe aa chuka hoga
        }
        return ans;
    }
};