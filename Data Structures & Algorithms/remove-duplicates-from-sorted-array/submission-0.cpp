class Solution {
public://approach-1> extra space
    int removeDuplicates(vector<int>& nums) {
        vector<int>temp;

        temp.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(temp.back()!=nums[i]){
                temp.push_back(nums[i]);
            }
        }
        int k=0;

        while(k<temp.size()){
            nums[k]=temp[k];
            k++;
        }
        return k;
    }
};