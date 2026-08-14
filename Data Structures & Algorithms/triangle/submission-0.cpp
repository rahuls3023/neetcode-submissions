class Solution {
public:
    int recursion(int row,int col,vector<vector<int>>&triangle){
        //base case
        if(row==triangle.size()-1){
            return triangle[row][col];
        }

        int down=triangle[row][col]+recursion(row+1,col,triangle);
        int diagonal=triangle[row][col]+recursion(row+1,col+1,triangle);

        return min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return recursion(0,0,triangle);
    }
};