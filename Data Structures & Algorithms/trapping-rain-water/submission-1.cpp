class Solution {
public://better approach-> precompute leftmax and rightmax array
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int>leftMax(n);
        vector<int>rightMax(n);

         // leftMax[i] = index 0 se i tak maximum height
         leftMax[0]=height[0];//leftmost ka leftmax wo khud hi hoga

         for(int i=1;i<n;i++){
            leftMax[i]=max(height[i],leftMax[i-1]);
         }

         //rightMax[i]=index i se n-1 tk mese maximum height
         rightMax[n-1]=height[n-1];

         for(int j=n-2;j>=0;j--){
            rightMax[j]=max(rightMax[j+1],height[j]);
         }

         //now calculate for every index
         int maxWater=0;
         for(int i=0;i<n;i++){
            int waterAtCurrentBar =min(leftMax[i],rightMax[i])-height[i];

            maxWater+=waterAtCurrentBar ;
        }
        return maxWater;
    }
};
