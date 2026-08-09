class Solution {
public:
    int recursion(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n) return 0;

        if(i==m-1 && j==n-1){
            return 1;
        } 

        //we can have two options

        int down=recursion(i+1,j,m,n);

        int right=recursion(i,j+1,m,n);

        return (down+right);
    }
    int uniquePaths(int m, int n) {
        return recursion(0,0,m,n);
    }
};