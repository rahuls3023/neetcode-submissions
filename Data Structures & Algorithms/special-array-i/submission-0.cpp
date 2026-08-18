class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int oddCount=0;
        int evenCount=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                evenCount++;
            }
            else{
                oddCount++;
            }
        }

        if(evenCount==oddCount+1 || oddCount==evenCount+1){
            return true;
        }
        else return false;
    }
};