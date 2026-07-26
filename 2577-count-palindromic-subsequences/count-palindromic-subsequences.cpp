class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        // prefix[i][a][b] = number of subsequences "ab" in s[0...i]
        vector<vector<vector<long long>>> prefix(
            n, vector<vector<long long>>(10, vector<long long>(10, 0)));

        // suffix[i][a][b] = number of subsequences "ab" in s[i...n-1]
        vector<vector<vector<long long>>> suffix(
            n, vector<vector<long long>>(10, vector<long long>(10, 0)));

        // Count of each digit seen so far
        vector<long long> cnt(10, 0);

        // ---------- Build prefix ----------
        for (int i = 0; i < n; i++) {

            if (i > 0)
                prefix[i] = prefix[i - 1];

            int d = s[i] - '0';

            // Every previous digit forms a pair with current digit
            for (int x = 0; x < 10; x++) {
                prefix[i][x][d] += cnt[x];
            }

            cnt[d]++;
        }

        // ---------- Build suffix ----------
        fill(cnt.begin(), cnt.end(), 0);

        for (int i = n - 1; i >= 0; i--) {

            if (i < n - 1)
                suffix[i] = suffix[i + 1];

            int d = s[i] - '0';

            // Current digit forms pair with every digit after it
            for (int x = 0; x < 10; x++) {
                suffix[i][d][x] += cnt[x];
            }

            cnt[d]++;
        }

        long long ans = 0;

        // Choose middle character
        for (int mid = 2; mid <= n - 3; mid++) {

            // Try every pair (a,b)
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {

                    long long left = prefix[mid - 1][a][b];
                    long long right = suffix[mid + 1][b][a];

                    ans = (ans + left * right) % MOD;
                }
            }
        }

        return ans;
    }
};