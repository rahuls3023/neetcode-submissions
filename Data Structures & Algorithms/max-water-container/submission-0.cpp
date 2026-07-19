class Solution {
public://brute force-> check every pair
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maximumAmount=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int width=j-i;

                int containerHeight=min(heights[i],heights[j]);

                int current=width*containerHeight;

                maximumAmount=max(maximumAmount,current);
            }
        }
        return maximumAmount;
    }
};
