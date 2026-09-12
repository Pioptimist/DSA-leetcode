class Solution {
public://0
    void f(int i , int j , int n , int m , vector<vector<char>>& board){
        board[i][j] = '#';

        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(auto d : dir){

            int newr = i + d[0];
            int newc = j + d[1];

            if(newr >=0 && newr < n && newc >=0 && newc < m && board[newr][newc] == 'O'){
                f(newr , newc , n , m , board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(board[i][j] == 'O' && (i==0 || i == n-1 || j==0 || j==m-1)){
                    f(i , j , n , m , board);
                }
            }
        }
//now every boundary o and those connected to them are # , turn the rest o into x
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(board[i][j] == 'O' ){
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(board[i][j] == '#' ){
                    board[i][j] = 'O';
                }
            }
        }


        
    }
};