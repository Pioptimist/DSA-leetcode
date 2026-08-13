class Solution {
public:
    int n, m;

    unsigned int f(int i, int j, vector<vector<unsigned int>> &dp, string &s, string &t) {
        
        if (j > m - 1) return 1;   
        if (i > n - 1) return 0;   

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            // Match: kya pta aage jaake ek aur match mil jaye hence skip this match plus match the chars and move ahead.
            return dp[i][j] = f(i + 1, j, dp, s, t) + f(i + 1, j + 1, dp, s, t);
        }

        // Mismatch: skip current character in s
        return dp[i][j] = f(i + 1, j, dp, s, t);
    }

   

    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();

        vector<vector<unsigned int>> dp(n, vector<unsigned int>(m, -1));
        return f(0, 0, dp, s, t);
    }


    int numDistinctTabulation(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0));
        
        // Base Case 1: If j == m (target string t is fully matched), we found 1 valid way!
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        // Base Case 2: If i == n and j < m (s ran out but t didn't), dp[n][j] is already 0.
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                 
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};

