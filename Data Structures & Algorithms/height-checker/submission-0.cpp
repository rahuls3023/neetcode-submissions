class Solution {
public://approach-1> sorting approach
    int heightChecker(vector<int>& heights) {
        vector<int>originalHeights=heights;
        vector<int>expectedHeights=heights;
        sort(begin(expectedHeights),end(expectedHeights));

        int count=0;
        for(int i=0;i<expectedHeights.size();i++){
            if(expectedHeights[i]!=originalHeights[i]){
                count++;
            }
        }
        return count;
    }
};