class Solution {
public:
    int n;
    int m;

    int f(int i , int j , vector<vector<int>>& matrix , vector<vector<int>> &dp){
        if(i == n-1 ) return matrix[i][j];

        if(dp[i][j] != 1e9) return dp[i][j];

        int dir[3][2] = { {1,0} , {1 , -1} , {1 , 1} };
        int sm = INT_MAX;
        for(auto d: dir){
            int nr = i + d[0];
            int nc = j + d[1];
            if(nc >= m || nr >= n) continue;

            if(nc < 0 || nr < 0) continue;

            sm = min(sm , matrix[i][j] + f(nr , nc , matrix , dp));   
        }

        return dp[i][j] = sm;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n , vector<int>(m , 1e9));
//dont use -1 to initialse dp bcz -1 is a valid state in this ques which will lead to tle as our solution will recompute again and again.
        int ans = INT_MAX;
        for(int j = 0 ; j < m ; j ++){
            ans = min(ans , f(0 , j , matrix , dp));
        }

        // return ans;

        vector<int> prev = matrix[n-1];

        for(int i = n-2; i >=0; i--) {
            vector<int> curr(m);

            for(int j = 0; j < m; j++) {
               int down = prev[j];

               int left = (j > 0) ? prev[j-1] : INT_MAX;
               int right = (j < m-1) ? prev[j+1] : INT_MAX;

               curr[j] = matrix[i][j] + min({down, left, right});
            }

            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
  
    }
};