class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    vector<ll> fact, invfact;

    ll modpow(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
    }

    int solve(vector<int>& nums) {
        int m = nums.size();
        if (m < 3) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < m; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        ll leftways  = solve(left);
        ll rightways = solve(right);

        return (((leftways * rightways) % MOD) * nCr(m-1, left.size())) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        fact.resize(n+1);
        invfact.resize(n+1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % MOD;
        invfact[n] = modpow(fact[n], MOD-2);
        for (int i = n-1; i >= 0; i--) invfact[i] = (invfact[i+1] * (i+1)) % MOD;

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
