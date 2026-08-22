class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int n, int m) {
        grid[r][c] = 0; // "Sink" the land cell directly

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                dfs(nr, nc, grid, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Traverse only the First and Last Column
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(i, 0, grid, n, m);
            if (grid[i][m - 1] == 1) dfs(i, m - 1, grid, n, m);
        }

        // Traverse only the First and Last Row
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(0, j, grid, n, m);
            if (grid[n - 1][j] == 1) dfs(n - 1, j, grid, n, m);
        }

        // Count remaining trapped land cells
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// class Solution {
// public:
//     void dfs(int i, int j , vector<vector<int>>& grid, vector<vector<int>> &vis, int n , int m){
//         vis[i][j] = 1;
//         int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
//         for(int d = 0; d<4 ; d++){
//             int newr = i + dir[d][0];
//             int newc = j + dir[d][1];
//             if(newr>=0 && newr<n && newc >=0 && newc<m && vis[newr][newc] == 0 && grid[newr][newc]==1){
                
//                 dfs(newr , newc , grid , vis , n, m);
//             }
//         }
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n,vector<int>(m,0));

//         for(int i =0; i< n; i++){
//             for(int j =0; j< m; j++){
//                 if(!vis[i][j] && (i == 0 || i == n-1 || j == 0 || j == m-1)){
//                     if(grid[i][j] == 1){
                        
//                         dfs(i,j , grid ,vis , n , m);
//                     }
//                 }
//             }
//         }
//         int cnt  = 0;
//         for(int i =0;i < n ; i++){
//             for(int j =0; j < m ; j++){
//                 if(vis[i][j] != 1){
//                     if(grid[i][j] == 1){
//                         cnt++;
//                     }
//                 }
//             }
//         }

//         return cnt;
        
//     }
// };