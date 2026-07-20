class MinStack {
public://approach-2> using 2 stack
    stack<int>st;
    stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minSt.empty() || minSt.top()>=val){
            minSt.push(val);
        }
    }
    
    void pop() {
        if(st.top()==minSt.top()){
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
