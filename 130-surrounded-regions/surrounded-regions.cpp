class Solution {
public:
    void dfs(int i, int j , vector<vector<char>>& board, vector<vector<int>> &vis, int n , int m){
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int d = 0; d<4 ; d++){
            int newr = i + dir[d][0];
            int newc = j + dir[d][1];
            if(newr>=0 && newr<n && newc >=0 && newc<m && vis[newr][newc] == 0 && board[newr][newc]=='O'){
                vis[newr][newc] = 1;
                dfs(newr , newc , board , vis , n, m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i =0; i< n; i++){
            for(int j =0; j< m; j++){
                if(!vis[i][j] && (i == 0 || i == n-1 || j == 0 || j == m-1)){
                    if(board[i][j] == 'O'){
                        vis[i][j] = 1;
                        dfs(i,j , board ,vis , n , m);
                    }
                }
            }
        }

        for(int i =0;i < n ; i++){
            for(int j =0; j < m ; j++){
                if(vis[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};