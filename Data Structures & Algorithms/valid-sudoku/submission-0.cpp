class Solution {
public://optimal way
    bool validBox(vector<vector<char>>& board,int sr,int er,int sc,int ec){
        unordered_set<char>st;

        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(board[i][j]=='.') continue;

                if(st.find(board[i][j])!=st.end()) return false;

                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        //validate rows
       //validate rows
        for(int row=0;row<9;row++){
            unordered_set<char>st;
            for(int col=0;col<9;col++){
                if(board[row][col]=='.') continue;

                if(st.find(board[row][col])!=st.end()) return false;//duplicate found
                st.insert(board[row][col]);
            }
        }

        //validate cols
        for(int col=0;col<9;col++){
            unordered_set<char>st;
            for(int row=0;row<9;row++){
                if(board[row][col]=='.') continue;

                if(st.find(board[row][col])!=st.end()){
                    //duplicate value
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        //check 3*3 matrix
        //sr=start row,
        for(int sr=0;sr<9;sr+=3){//+=3 kyuki ab next 3*3 matrix me jump krna h
            int er=sr+2;//end row

                for(int sc=0;sc<9;sc+=3){//+=3 kyuki ab next 3*3 matrix me jump krna h
                    //sc=start col
                    int ec=sc+2;//end col

                    if(!validBox(board,sr,er,sc,ec))return false;
                }
        }
        return true;
    }
};
