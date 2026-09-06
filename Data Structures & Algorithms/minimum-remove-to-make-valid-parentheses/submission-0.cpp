class Solution {
public://using set and stack, set me store kr lege to find konsa remove krna h as o(1) operation
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        unordered_set<int>remove_idx;
        stack<int>st;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    remove_idx.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }

        //only open brackets (((
            while(!st.empty()){
                remove_idx.insert(st.top());
                st.pop();
            }

            string temp="";
            for(int i=0;i<n;i++){
                if(remove_idx.find(i)==remove_idx.end()){
                    temp.push_back(s[i]);
                }
            }
            return temp;
    }
};