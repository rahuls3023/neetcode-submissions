class MinStack {
public://approach-3> using 1 stack and encoded value concept
    stack<long long>st;
    long long mini;

    MinStack() {
        
    }
    
    void push(int val) {
          //if stack is empty ,first element is minimum
        if(st.empty()){
            st.push(val);
            mini=val;
        }
          //if new value is greater than or equal to current minimum, push normally
        else if(mini<=val){
            st.push(val);
        }
         //if new value is smaller than or equal to current minimum,
        // we wont push it normally, we will push the encoded value
        else{
               st.push(2LL*val-mini);
            mini=val;//update the minimum value;
        }
    }
    
    void pop() {
         //if top is normal value
        //simply remove it
        if(st.top()>=mini){
            st.pop();
        }

        //otherwise top is encoded value
        //decode the previous minimum before popping
        else{
            mini=2*mini-st.top();
            st.pop();
        }
    }
    
    int top() {
          //if top is normal value, return it
        if(st.top()>=mini){
            return st.top();
        }

         // If top is encoded,
        // actual top element is the current minimum.
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};
