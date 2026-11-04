class Solution {
public:
    long f(int n , int m , int i , int j , vector<vector<int>>& grid){
        if(i == n || j == m) return INT_MAX; //grid ke bahar mtlb yeh wala path not possible , prune krdo 

        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        long down = grid[i][j] + f(n , m , i +1 , j , grid);
        long right = grid[i][j] + f(n , m , i , j+1 , grid);

        return min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         
        
        // return f(n,m , 0 , 0 , grid);
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 1e9));
        dp[n-1][m-1] = grid[n-1][m-1];
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = m-1 ; j >=0 ; j--){
                if(i == n-1 && j == m-1) dp[i][j] = grid[i][j];
                else {
                    dp[i][j] = min(grid[i][j] + dp[i+1][j] , grid[i][j] + dp[i][j+1]);
                }
                
            }
        }
        return dp[0][0];
 
    }
};