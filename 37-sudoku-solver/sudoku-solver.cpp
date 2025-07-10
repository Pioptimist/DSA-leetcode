class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char c){
        for(int i =0;i<9;i++){
            if(board[i][col]==c) return false;   //check rows
            if(board[row][i]==c) return false;   //check columns
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c) return false;     // check that particular 3*3 box
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c = '1';c<='9';c++){
                        if(isvalid(board,i,j,c)==true){
                            board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};