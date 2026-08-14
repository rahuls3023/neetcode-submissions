class Solution {
public:
    int m;
    int n;
    int recursion(int i,int j,vector<vector<int>>&obstacleGrid){
        if(i<0 || j<0 || i>=m || j>=n || obstacleGrid[i][j]==1) return 0;

        if(i==m-1 && j==n-1) return 1;

        int down=0;
        if(i+1<m){
            down=recursion(i+1,j,obstacleGrid);
        }

        int right=0;
        if(j+1<n){
            right=recursion(i,j+1,obstacleGrid);
        }

        return down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        return recursion(0,0,obstacleGrid);
    }
};