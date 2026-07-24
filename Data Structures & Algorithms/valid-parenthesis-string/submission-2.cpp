class Solution {
public://using 2 stacks
    bool checkValidString(string s) {
        stack<int>st;
        stack<int>asteriskSt;

        for(int i=0;i<s.size();i++){
            if( s[i]=='('){
                st.push(i);//we r pushing index instead of brckets
            }
            else if(s[i]=='*'){
                asteriskSt.push(i);
            }
            else{
                //s[i]==')'
                if(!st.empty()){
                    //not empty means, top pe ( hoga
                    st.pop();
                }
                else if(!asteriskSt.empty()){
                    //can help me in balance
                    // agar st empty h to hum dusre stack waale * ko open bracket maan skte h (
                    asteriskSt.pop();
                }
                else{
                    return false;
                }
            }
        }

        //now we will check whether st is empty or not , if it is empty return true directly if it is not check for asterisk.
        while(!st.empty() && !asteriskSt.empty()){
            if(st.top()>asteriskSt.top()){
                //iska mtlb start kahi open bracket se pehle aya h , to ( se kese match hoga
                return false;
            }
            st.pop();
            asteriskSt.pop();
        }
        if(st.empty()) return true;
        else return false;
    }
};