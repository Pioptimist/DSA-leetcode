class Solution {
public:
    int M = 1e9 + 7;
    vector<int> dp;

    int f(string &s, int k, int n, int i) {
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        long num = 0;
        long ans = 0;

        for (int j = i; j < n; j++) {
            num = num * 10 + (s[j] - '0');

            if (num > k) break;

            ans = (ans + f(s, k, n, j + 1)) % M;
        }

        return dp[i] = ans;
    }

    int numberOfArrays(string s, int k) {
        int n = s.size();
        dp.resize(n, -1);
        return f(s, k, n, 0);
    }
};