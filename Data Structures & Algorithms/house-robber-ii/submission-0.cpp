class Solution {
public:
    int recursion(int index,vector<int>nums,int n){
        if(index>n){//yaha >= nhi kra kyu is nth index ke house ko bhi chori kr skta hu me islie iski value bhi consider kr skte h
            return 0;
        }

        //agar current house me steal kre
        int steal=0;
        steal+=nums[index]+recursion(index+2,nums,n);

        //skip current house
        int not_steal=0;
        not_steal+=recursion(index+1,nums,n);

        return max(steal,not_steal);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        //agar first wale me chori krle to last me n-1 as neighbour h to waha to usme chori nhi kr skte
        int stealFirst=recursion(0,nums,n-2);
        //agar first me chori nhi kri to n-1 house me chori kr skte h
        int stealSecond=recursion(1,nums,n-1);
        return max(stealFirst,stealSecond);

    }
};