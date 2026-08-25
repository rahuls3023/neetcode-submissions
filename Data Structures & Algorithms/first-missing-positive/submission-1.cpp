class Solution {
public://optimal approach
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        //as hume 1 se n tk hi number check krne hai isliye agar koi bhi number <= 0 ya fir >n iska mtlb unka koi relevant index nhi h isliye , n+1 se replace krdo.
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=n+1;
            }
        }

        //now we will do marking

        //ab har value ko uske corresponding index par mark krege.
        //value x ka corresponding index x-1 hoga.
        //agar wo value present h, to nums[value-1] ko negative kr denge.
        //negative ka mtlb hoga ki ye value array me present h.
        for(int i=0;i<n;i++){
            int value=abs(nums[i]);
            int index=value-1;

            if(value<=n){
                if(nums[index]>0){//pehle se to -ve nhi h ye index
                    nums[index]=-nums[index];
                }
            }
        }

        for(int i=0;i<n;i++){
            //jo bhi positive hoga number mtlb uska index +1  wala number present nhi h
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};