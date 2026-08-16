class Solution {
public://approach-1>
    string longestCommonPrefix(vector<string>& strs) {
        string base=strs[0];

        for(int i=1;i<strs.size();i++){
            string curr=strs[i];

            int j=0;

            while(j<curr.size() && j<base.size() && base[j]==curr[j]){
                j++;
            }
            base=base.substr(0,j);
        }
        if(base=="") return "";
        else return base;
    }
};