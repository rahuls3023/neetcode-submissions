class Solution {
public:
    vector<int>findPrevSmaller(vector<int>&heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans;

        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }

    vector<int>findNextSmaller(vector<int>&heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans;

        for(int i=heights.size()-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> prevSmaller = findPrevSmaller(heights);
        vector<int> nextSmaller = findNextSmaller(heights);

        //jaha bhi nextsmaller me -1 h uski jagah heights.size() dalna hoga as jiska next smaller nhi h uske lie size ayega .

        //nextsmaller ke jaha -1 h uski jagah uska nextSmaller index hamesha size ke equal hoga of heights

        for(int i=0;i<nextSmaller.size();i++){
            if(nextSmaller[i]==-1){
                nextSmaller[i]=heights.size();
            }
        }

        //now reverse the nextSmaller array as hum ulta traverse kr rhe the usme aur upar se stack bhi use kr rhe the.
        reverse(nextSmaller.begin(),nextSmaller.end());

        int maximumArea=0;
        for(int i=0;i<n;i++){
            int width=nextSmaller[i]-prevSmaller[i]-1;//-1 kyuki ek khudka size bhi hta rhe h
            int currentArea=heights[i]*width;
            maximumArea=max(maximumArea,currentArea);
        }
        return maximumArea;
    }
};
