class Solution {
public:

    bool isSafe(int row,int col,vector<string>&board,int n){
        //as we r putting row wise we will check for upper part, left upper diagonal and right uppper diagonal

        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //left diagonal upwards
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            //left upar jarhe h to row bhi kamm horhe hai aur left jarhe h isliye colmn bhi kamm
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //right diagonal upwards
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }


    void solve(int n,int row,vector<string>&board,vector<vector<string>>&ans){
        if(row>=n){
           ans.push_back(board);
           return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(n,row+1,board,ans);
                //backtrack
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;

       vector<string>board(n,string(n,'.'));
        int row=0;

        solve(n,row,board,ans);
        return ans;
    }
};