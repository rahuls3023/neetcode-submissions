class Solution {
public://optimal approach-> using monotonic stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>result(n);

        for(int i=n-1;i>=0;i--){
            //jo temperatures current temp se choti ya equal hai
            //wo uske lie warmer nhi ho skti

            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
             //agar stack empty nhi h to
            //stack ke top wala index , nearest warmer day ka index h
            if(!st.empty()){
                result[i]=st.top()-i;
            }
            st.push(i);
        }
        return result;
    }
};
