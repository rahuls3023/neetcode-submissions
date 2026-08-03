class Solution {
public://optimal-> 2 pointer
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;

        int maxAmount=0;

        while(i<j){
            int width=j-i;
            int containerHeight = min(height[i], height[j]);

            maxAmount=max(maxAmount,width*containerHeight);

            //Current area ko kaunsi chhoti wall limit kar rahi hai? Usi pointer ko move karo.
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxAmount;
    }
};