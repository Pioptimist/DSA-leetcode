class Solution {
public:
    int n;
    int m;
    bool dfs(int i , int j , int k ,vector<vector<char>>& board, string &word){
        if(k == word.size()-1){
            return true;
        }

        board[i][j] = '#';
        int dir[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};

        for(auto d : dir){
            int nr = i + d[0];
            int nc = j + d[1];

            if(nr >=0 && nr < n && nc >=0 && nc < m && board[nr][nc] == word[k+1]){
                if(dfs(nr , nc , k+1 , board , word)){
                    return true;
                }
            }
        }
        board[i][j] = word[k];
        return false;

    }



    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i , j , 0 ,board , word)){
                        return true;
                    }
                }
            }
        }
        return false;
        
        
    }
};