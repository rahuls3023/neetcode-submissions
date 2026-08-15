class Solution {
public:
    int recursion(int i,int j,vector<vector<char>>& matrix){
        
        if(i<0 || j<0) return 0;

        //agar current cell 0 h to isko include krke square nhi ban skta
        if(matrix[i][j]=='0') return 0;

        //current cell ko bottom-right corner maan rhe h
        //square ki size depend kregi top, left aur diagonal ke minimum par
        //+1 current cell ke lie
        return 1 + min({
            recursion(i-1,j,matrix),      //top
            recursion(i,j-1,matrix),      //left
            recursion(i-1,j-1,matrix)     //diagonal
        });
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        //maximum square ki side length store krega
        int result=INT_MIN;

        //har cell ko bottom-right corner maan ke check kro
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                //current cell se banne wale square ki maximum side nikalo
                result=max(result,recursion(i,j,matrix));
            }
        }

        //recursion side length return krta h
        //question area maang rha h -> side * side
        return result*result;
    }
};