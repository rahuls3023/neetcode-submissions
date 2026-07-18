class Solution {
public://division approach-> better approach
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        //calculate the count of zero and product of elements without 0
        int count0=0;
        int totalProd=1;

        for(int i=0;i<n;i++){
            if(nums[i]==0)count0++;
            else totalProd*=nums[i];
        }

        vector<int>ans(n);

        //now traverse the array again
        for(int i=0;i<n;i++){
            //check kro current element 0 hai ya nhi
            if(nums[i]!=0){
                //ab check kro agar count0 >0 hai , iska ye mtlb hua ki as current to 0 hai nhi aur count0 bhi!=0 hai iska mtlb kahi aur zero hai,
                //array me to iska product 0 hoga
                if(count0>0){
                    ans[i]=0;
                }
                else{
                    //agar count0=0 hai, iska mtlb aage 0 nhi h kahi bhi 
                    ans[i]=totalProd/nums[i];
                }
        }

        else{
            //agar nums[i]==0 hogya,to check krege kya current 0 ke alawa aur kahi to nhi h zero in the entire array
            if(count0>1){
                ans[i]=0;
            }
            else{
                //iska mtlb count0<1 hai iska mtlb current ke alawa aur kahi zero nhi h
                ans[i]=totalProd;
            }
        }
    }
        return ans;
    }
};
