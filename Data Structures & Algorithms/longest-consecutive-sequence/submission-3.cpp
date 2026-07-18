class Solution {
public://approach-3> set
    // pehle hum saare number ko hashset me dalege fir set traverse krege
    // check krege kya value-1 present in hashset or not,
    // if yes to current value is not starting sequence
    // if not then current is starting and uske aage ka sequence search krege.
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;
        
        //step-1> store number in hashset
        unordered_set<int>st(nums.begin(),nums.end());

        int longest=1;

        //step-2> traverse hashset

        //array ko nhi kr rhe kyuki usme duplicates ho skte h jisse tle ajayega
        for(auto it:st){
            int currentNum=it;

            //check if this number is starting of sequence or not
            if(st.find(currentNum-1)==st.end()){
                //num-1 set me nhi h mtlb isi number se sequence start hoga
                int currentLength=1;

                while(st.find(currentNum+1)!=st.end()){
                    //search kro sequence x+1,x+2.....
                    currentLength++;
                    currentNum++;
                }

                longest=max(longest,currentLength);
            }
        }

        return longest;
    }
};