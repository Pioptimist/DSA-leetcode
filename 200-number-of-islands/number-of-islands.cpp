class Solution {
public:
    void dfs(int i ,int j , vector<int> &vis,vector<vector<char>>& grid,int n, int m){
        
        int node = m*i + j;
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='1' && !vis[node]){
            vis[node] = 1;
            dfs(i-1 , j , vis , grid , n , m);
            dfs(i+1 , j , vis , grid , n , m);
            dfs(i , j -1 , vis , grid , n , m);
            dfs(i , j + 1 , vis , grid , n , m);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> vis(n*m , 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] == '1'){
                    if(!vis[m*i + j]){
                        cnt++;
                        dfs(i , j , vis , grid , n , m);
                    }
                }
            }
        }

        return cnt;
        
    }
};