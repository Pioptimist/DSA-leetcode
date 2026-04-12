class Solution {
public:
    int MOD = 1e9 + 7;
    int n , m;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> dp;
    bool isSafe(int i , int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    int dfs(vector<vector<int>> &grid , int i , int j){
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1;
        for(auto d : dir){
            int nr = i + d[0];
            int nc = j + d[1];

            if(isSafe(nr,nc) && grid[nr][nc] < grid[i][j]){
                ans = (ans + dfs(grid , nr , nc)) % MOD;
            }
        }

        return dp[i][j] = ans%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        long long res = 0;
        dp.assign(n, vector<int>(m, -1));
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                res = (res%MOD + dfs(grid , i , j)%MOD)%MOD;
            }
        }

        return res;
        
    }
};