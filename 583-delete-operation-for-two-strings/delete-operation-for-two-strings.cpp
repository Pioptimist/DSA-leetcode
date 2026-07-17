class Solution {
public:
    int minDistance(string word1, string word2) {
//idea simle hai , to find min number of operation to convert word1 to word2 , means jo unke beechme longest common subseq hai , humko word1 ko usme convert krna hoga and same for word2 so total operations to do that will be n - lcs + m - lcs.
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int lcs = dp[n][m];
        return n + m - 2 * lcs;
    }
};