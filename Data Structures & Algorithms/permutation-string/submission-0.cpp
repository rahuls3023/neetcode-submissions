class Solution {
public://brute force.
    bool checkInclusion(string s1, string s2) {
        //check all substrings of s2 if it is permutation of s1

        int m=s1.size();
        int n=s2.size();

        //store frequency of s1.
        unordered_map<char,int>target;
        for(auto it:s1){
            target[it]++;
        }

        for(int i=0;i<n;i++){

            unordered_map<char,int>curr;//store freq of every substring

            for(int j=i;j<n;j++){
                curr[s2[j]]++;

                if(curr==target) return true;
            }
        }
        return false;
    }
};
