class Solution {
public:
    int f(int m , int n , int i, int j , vector<vector<int>> &dp){
        if(i == m || j == n){
            return 0;
        }
        if(i == m-1 && j == n-1) return 1;
        
        if(dp[i][j] !=-1) return dp[i][j];
        int down = f(m , n , i+1 , j , dp);
        int right = f(m , n , i , j+ 1, dp);
        
        
        return dp[i][j] = down + right;


    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m , vector<int>(n,-1));
        // return f(m , n , 0 , 0 , dp);
        vector<vector<int>> dp(m + 2 , vector<int>(n + 2,0));
        dp[m-1][n-1] = 1;
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n -1 ; j>=0 ; j--){

                if(i==m-1 && j==n-1) continue;

                dp[i][j] = dp[i+1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};