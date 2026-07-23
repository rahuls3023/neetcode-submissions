class Solution {
public:
    bool solve(int index,int i,int j,vector<vector<char>>&board,string &word){
        if(index==word.size()){
            //match hogya sara
            return true;
        }

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='*') return false;

        if(board[i][j]!=word[index]){
            //no need to go further as match nhi kr rha h
            return false;
        }

        char currentWord=word[index];

        board[i][j]='*';//marking it

        //we can now go 4 directions

        bool found=solve(index+1,i-1,j,board,word) || solve(index+1,i,j-1,board,word) || solve(index+1,i,j+1,board,word) || solve(index+1,i+1,j,board,word);

        //backtrack
        board[i][j]=currentWord;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if( board[i][j]==word[0] &&  solve(0,i,j,board,word)){//we will start checking whenever we get the first element of word in matrix, from there we can go 4 directions
                    return true;
                }
            }
        }
        return false;
    }
};