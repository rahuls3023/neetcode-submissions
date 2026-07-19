class Solution {
public://brute force
    int trap(vector<int>& height) {
        int n=height.size();
        int totalWater=0;

        for(int i=0;i<n;i++){
            int leftMax=0;
            int rightMax=0;
            
            ///find leftmax from 0 to i
            for(int j=0;j<=i;j++){
                leftMax=max(leftMax,height[j]);
            }

            //find rightmax from i to n-1;
            for(int j=i;j<n;j++){
                rightMax=max(rightMax,height[j]);
            }

             int waterAtIndex =
                min(leftMax, rightMax) - height[i];

                totalWater+=waterAtIndex;
        }
        return totalWater;
    }
};
