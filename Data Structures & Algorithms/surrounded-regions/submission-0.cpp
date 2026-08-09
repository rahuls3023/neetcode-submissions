class Solution {
public://bfs-> approach
//start from boundary , mark all cells which are connected from boundary
//temporary mark them '#' and rest will remain 'O'
//traverse again and mark 'O' to 'X' and '#' to 'O'.

    vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};

    void bfs(vector<vector<char>>& board,int row,int col){
         int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        board[row][col] = '#'; // mark as safe/visited

        while(!q.empty()){
            auto current=q.front();
            q.pop();

            for(auto &dir:directions){
                int newr=current.first+dir[0];
                int newc=current.second+dir[1];

                if(newr>=0 && newr<m && newc>=0 && newc<n && board[newr][newc]=='O'){
                    board[newr][newc]='#';
                    q.push({newr,newc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        //first and last coloumn
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
            bfs(board,i,0);

            if(board[i][n-1]=='O')
            bfs(board,i,n-1);
        }

        //first and last row
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')
            bfs(board,0,i);

            if(board[m-1][i]=='O')
            bfs(board,m-1,i);
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