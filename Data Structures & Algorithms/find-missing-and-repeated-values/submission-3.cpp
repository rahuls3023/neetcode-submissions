class Solution {
public://optimal approach-< O(N^2) AND O(1).
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        int N=n*n;

        long long gridSum=0;
        long long gridsquareSum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gridSum+=grid[i][j];
                gridsquareSum+=grid[i][j]*grid[i][j];
            }
        }

        long long sum=(N*(N+1))/2;//EXPECTED SUM OF FIRST N NATURAL NUMBERS

        long long sqsum=(N*(N+1)*(2*N+1))/6;//EXPECTED SQUARE SUM OF N NATURAL NUMBERS

        int sqDiff=gridsquareSum-sqsum;

        int sumDiff=gridSum-sum;

        int a=(sqDiff/sumDiff+sumDiff)/2;

        int b=(sqDiff/sumDiff-sumDiff)/2;

        return {a,b};
    }
};