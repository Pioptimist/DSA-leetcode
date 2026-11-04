class Solution {
public:
    int f(int i , int j , int n , int m , vector<vector<int>>& matrix ,  vector<vector<int>>& dp){
        if(i > n-1 || j > m-1 ) return 0;

        int maxW = 0;

        if(dp[i][j] != -1) return dp[i][j];
        int dir[4][2] = {{0,1} , {0,-1} , {1,0} , {-1 ,0}};
        for(auto d : dir){
            int r = i + d[0];
            int c = j + d[1];

            if(r >= 0 && c >=0 && r < n && c < m){
                if(matrix[r][c] >= matrix[i][j]) continue;

                maxW = max(maxW , f(r , c , n , m , matrix , dp));

            }
        }

        return dp[i][j] = 1 + maxW;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                maxi = max(maxi , f(i , j , n , m , matrix , dp));
            }
        }

        return maxi;
        
    }
};