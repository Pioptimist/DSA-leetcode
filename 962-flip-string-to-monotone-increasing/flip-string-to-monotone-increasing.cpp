class Solution {
public:
    int f(string &s, int i, int p, vector<vector<int>> &dp){
        if(i == s.size()) return 0;

        if(dp[i][p] != -1) return dp[i][p];

        int flip = INT_MAX, nflip = INT_MAX;

        if(s[i] == '0'){
            if(p == 0){
                nflip = f(s, i+1, 0, dp);
                flip  = 1 + f(s, i+1, 1, dp);
            } else {
                flip  = 1 + f(s, i+1, 1, dp);
            }
        }
        else{
            if(p == 0){
                flip  = 1 + f(s, i+1, 0, dp);
                nflip = f(s, i+1, 1, dp);
            } else {
                nflip = f(s, i+1, 1, dp);
            }
        }

        return dp[i][p] = min(flip, nflip);
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(s, 0, 0, dp);
    }
};