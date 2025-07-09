class Solution {
public:
    void solve (vector<vector<string>> &ans, vector<string> &board,vector<int> &lowdiag, vector<int> &uppdiag,int n,vector<int> &hascol,int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
          
        for(int row =0;row<n;row++){
            if(hascol[row]==0 && uppdiag[n-1+col-row]==0 && lowdiag[row+col]==0){
                board[row][col]='Q';
                hascol[row]=1;
                uppdiag[n-1+col-row]=1;
                lowdiag[row+col]=1;
                solve(ans,board,lowdiag,uppdiag,n,hascol,col+1);
                board[row][col]='.';
                hascol[row]=0;
                uppdiag[n-1+col-row]=0;
                lowdiag[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> hascol(n,0);
        vector<string> board(n);
        vector<int> lowdiag(2*n-1,0);
        vector<int> uppdiag(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(ans,board,lowdiag,uppdiag,n,hascol,0);
        return ans;
        
    }
};