class Solution {
public://dfs-> approach
//start from boundary , mark all cells which are connected from boundary
//temporary mark them '#' and rest will remain 'O'
//traverse again and mark 'O' to 'X' and '#' to 'O'.

    void dfs(vector<vector<char>>& board,int row,int col){
         int m = board.size();
        int n = board[0].size();

        if(row<0 || col<0 || row>=m || col>=n || board[row][col]!='O') return;

        board[row][col] = '#'; // mark as safe/visited

        dfs(board,row+1,col);
        dfs(board,row-1,col);
        dfs(board,row,col-1);
        dfs(board,row,col+1);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        //first and last coloumn
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
            dfs(board,i,0);

            if(board[i][n-1]=='O')
            dfs(board,i,n-1);
        }

        //first and last row
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')
            dfs(board,0,i);

            if(board[m-1][i]=='O')
            dfs(board,m-1,i);
        }

        // Now:
        // O = not connected to boundary -> surrounded -> X
        // # = connected to boundary -> safe -> O
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }

    }
};