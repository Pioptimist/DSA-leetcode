class Solution {
public:
    int f(vector<vector<int>>& obstacleGrid , int n , int m ,int i , int j, 
    vector<vector<int>> &dp){
        if(i == n || j == m || obstacleGrid[i][j] == 1){ //obstacle path mein hoga hi nhi so prune this path
            return 0;
        }
        if(i == n-1 && j == m-1) return 1;

        if(dp[i][j] !=-1) return dp[i][j];

        int down = f(obstacleGrid, n , m , i+1 , j ,dp);
        int right = f(obstacleGrid , n , m , i , j+ 1, dp);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // vector<vector<int>> dp(n , vector<int>(m,-1));

        // return f(obstacleGrid , n , m , 0 , 0, dp);
        vector<vector<long long>> dp(n + 1 , vector<long long>(m + 1, 0));
        if(obstacleGrid[n-1][m-1]==1) return 0; // agr dest khud blocked hai toh

        dp[n-1][m-1] = 1; //otherwise dest is safe
        for(int i =n-1; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){

                if(i==n-1 && j==m-1) continue;

                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }

        return dp[0][0];
        
    }
};