class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool>remove(s.size(),false);
        stack<int>st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()) st.pop();//pair milgya to pop
                else remove[i]=true;//ye wala index include nhi krege as problem krega
            }
        }

        while(!st.empty()){//mark all indexes as false
            remove[st.top()]=true;
            st.pop();
        }
        string temp="";
        for(int i=0;i<s.size();i++){
            if(remove[i]==false){
                temp+=s[i];
            }
        }
        return temp;
    }
};