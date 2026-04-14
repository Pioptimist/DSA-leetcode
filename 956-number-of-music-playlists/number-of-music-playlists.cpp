class Solution {
public:
    int MOD = 1e9 + 7;
    long long dp[101][101];

    long long solve(int i, int j, int n, int k) {
        // Base case
        if (i == 0 && j == 0) return 1;
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = 0;

        // Pick a NEW song ie a uniq song
        ans += solve(i - 1, j - 1, n, k) * (n - (j - 1));

        //  Repeat a song from the uniq songs we have picked till now ie j
        if (j > k) {
            ans += solve(i - 1, j, n, k) * (j - k);
        }

        return dp[i][j] = ans % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(goal, n, n, k);
    }
};