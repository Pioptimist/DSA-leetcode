class Solution {
public:
    #define ll long long
    vector<vector<vector<ll>>> dp;
    int n;

    ll f(int i, ll k, vector<int>& nums, bool start_new) {
        if(k == 0)
            return 0;
        if(i >= n) {
           
            return -1e18;
        }

        if (dp[i][start_new][k] != LLONG_MIN) return dp[i][start_new][k];

        ll not_take = -1e18;
        ll take = -1e18;
    
        if (start_new == true) {
            not_take = f(i + 1, k, nums, true); // skip 
        }

        if (k%2 != 0) { 
            take = f(i + 1, k, nums, false) + nums[i] * k; //2 option honge isme
            take = max(take, f(i + 1, k - 1, nums, true) + nums[i] * k); //create new mein 3 option honge
        } else {
            take = f(i + 1, k, nums, false) - nums[i] * k;
            take = max(take, f(i + 1, k - 1, nums, true) - nums[i] * k);
        }

        return dp[i][start_new][k] = max(not_take, take);
    }

    ll maximumStrength(vector<int>& nums, int k) {
        ll ans = 0;
        n = nums.size();

        dp.resize(n + 1, vector<vector<ll>>(2, vector<ll>(k+1, LLONG_MIN)));
        
        bool start_new = true;

        return f(0, k, nums, start_new);
    }
};