class Solution {
public:
    int n;
    int m ;
    vector<vector<vector<int>>> dp;
    int f(vector<vector<int>>& grid , int r , int c1 , int c2){
        if(r >= n){
            return 0;
        }
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int cherry = grid[r][c1];
        if(c1 != c2){
            cherry += grid[r][c2];
        }
        int ans = 0;
        for(int i = -1 ; i<=1 ; i++){
            for(int j = -1 ; j <=1 ; j++){
                int newc1 = c1 + i;
                int newc2 = c2 + j;
                int newr = r + 1;
                
                if(newc1 >=0 && newc1 < m && newc2 >=0 && newc2 < m){
                    ans = max(ans , f(grid , newr , newc1 , newc2));
                }
            }
        }

        return dp[r][c1][c2] = ans + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n+1 , vector<vector<int>>(m , vector<int> (m , -1)));
        return f(grid ,  0 , 0 , m-1);
    }
};