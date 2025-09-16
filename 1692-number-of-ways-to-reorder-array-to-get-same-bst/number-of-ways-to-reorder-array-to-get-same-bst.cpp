class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    
    int solve(vector<int>& nums, vector<vector<ll>>& PT) {
        int m = nums.size();
        if (m < 3) return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < m; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        ll leftways  = solve(left, PT) % MOD;
        ll rightways = solve(right, PT) % MOD;

        return (((leftways * rightways) % MOD) * PT[m-1][left.size()]) % MOD;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> PT(n+1);

        for (int i = 0; i <= n; i++) {
            PT[i] = vector<ll>(i+1, 1);
            for (int j = 1; j < i; j++) {
                PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % MOD;
            }
        }

        return (solve(nums, PT) - 1 + MOD) % MOD; // +MOD for safety
    }
};
