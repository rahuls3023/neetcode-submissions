class Solution {
public://2 pointer-> optimal approach
    int trap(vector<int>& height) {
        int n=height.size();

        int left=0;
        int right=n-1;

        int leftMax=height[left];
        int rightMax=height[right];

        int totalWater=0;

        while(left<right){
            if(leftMax<=rightMax){
                //mtlb leftwaali boundary choti h right se to right me chahe kitni hi badi boundary miljaye koi frk nhi pdega as hum minimum hi lete h dono ka , iska mtlb left wala fixed hogya to usi se calculate kreg and usi ko move krege

                left++;

                  //jese hi if condition true hui iska mtlb leftmax already leftside ke maximum pe hoga, to pehle left increase krdo aur leftmax firse ek baar calculate krlo, kya pta bda miljaye aur fir trap nikaal lo

                  leftMax=max(leftMax,height[left]);

                  totalWater+=leftMax-height[left];
            }
            else{
                //leftmax>rightmax

                //same concept for right as well

                //rightmax chota hogya left se iska mtlb ab chahe leftmax kitna bhi bda hojaye as hum minimum rightmax hi lete h .

                //rightside fixed hai, isse calculate krege

                right--;

                rightMax=max(rightMax,height[right]);

                totalWater+=rightMax-height[right];
            }
        }
        return totalWater;
    }
};