class Solution {
public://optimal approach
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(int i=0;i<tokens.size();i++){
            //agar operator mila, last ke 2 operand pop and apply operation.

            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                 int result;

                if(tokens[i]=="+"){
                    result=right+left;
                    st.push(result);
                }
                else if(tokens[i]=="-"){
                    result=left-right;
                    st.push(result);
                }
                else if(tokens[i]=="*"){
                    result=left*right;
                    st.push(result);
                }
                else{
                    result=left/right;
                    st.push(result);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
