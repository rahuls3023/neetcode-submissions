class Solution {
public://brute force-> try all values
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        // for every element nums[i]:

        // treat nums[i] as the target value.
        // look at every other element.

        // If nums[j] < nums[i], calculate:

        // nums[i] - nums[j]

        // operations required.

        // keep subtracting operations from k until k becomes negative.
        // count how many elements can be made equal to nums[i].
        // take the maximum.

        sort(begin(nums),end(nums));

        int maxi=1;

        for(int i=0;i<n;i++){
            int remaining=k;
            int frequency=1;

            //try to make previous elemnt equal to nums[i]

            for(int j=i-1;j>=0;j--){
                //operations required to make nums[j]->nums[i];
                int operations=nums[i]-nums[j];

                //subtract the required operations from k
                remaining-=operations;

                // If remaining operations become negative, we cannot include
                // this element or any further smaller element.
                if(remaining < 0) {
                    break;
                }

                frequency++;
            }

            maxi=max(maxi,frequency);
        }
        return maxi;
    }
};