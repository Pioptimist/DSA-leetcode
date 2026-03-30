class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        int n = s1.size();
        int m = s2.size();
        if(i == n) return m - j;   
        if(j == m) return n - i;   

        if(dp[i][j] != -1) return dp[i][j];

        // match
        if(s1[i] == s2[j]) {
            return dp[i][j] = f(i+1, j+1, s1, s2, dp);
        }

        
        int del = 1 + f(i+1, j, s1, s2, dp);       
        int ins = 1 + f(i, j+1, s1, s2, dp);       
        int rep = 1 + f(i+1, j+1, s1, s2, dp);     

        return dp[i][j] = min({del, ins, rep});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, word1, word2, dp);
    }
};