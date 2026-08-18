class Solution {
public:
    //same code as n queens, only changes is that we have to return how many solutions we can have for n*n board;
    bool isSafe(int row,int col,vector<string>&board,int n){
        //check if another queen lies in same coloumn
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }

        //check for left upper diagonal
        //row-1 and col-1

        for(int i=row-1,j=col-1; i>=0 && j>=0 ; i--,j--){
            if(board[i][j]=='Q') return false;
        }

        //check for right upper diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int n,int row,vector<string>&board,vector<vector<string>> &ans){
        if(row>=n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';

                solve(n,row+1,board,ans);

                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;

        vector<string>board(n,string(n,'.'));

        solve(n,0,board,ans);

        return ans.size();
    }
};