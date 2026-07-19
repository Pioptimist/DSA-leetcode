class Solution {
public:
    int n, m;

    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {

        // Both strings consumed
        if (i == n && j == m) return true;

        // Pattern finished but string remains
        if (j == m) return false;

        // String finished
        if (i == n) {
            while (j < m) {
                if (p[j] != '*') return false;
                j++;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = f(i + 1, j + 1, s, p, dp);

        // Star
        if (p[j] == '*') {

            // '*' matches one character
            bool take = f(i + 1, j, s, p, dp);

            // '*' matches empty string
            bool skip = f(i, j + 1, s, p, dp);

            return dp[i][j] = take || skip;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        n = s.size();
        m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(0, 0, s, p, dp);
    }
};