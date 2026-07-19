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

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return f(0, 0, s, p, dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[n][m] = 1; //dono string out of bound mtlb matched

        for(int j=m-1;j>=0;j--){ //now check for when out of bound for string s , ki baaki ke char in in pattern p is * or not , if * => mark true

           if(p[j]=='*')  dp[n][j]=dp[n][j+1];
           else  dp[n][j]=false;
        
        }
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                

                if (s[i] == p[j] || p[j] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }

                else{
                    if(p[j] == '*'){
                        dp[i][j] = dp[i][j+1] || dp[i+1][j];
                    }
                }
            }
        }

        return dp[0][0];

    }
};