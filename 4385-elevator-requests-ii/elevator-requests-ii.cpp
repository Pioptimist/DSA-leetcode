class Solution {
public:
    typedef long long LL;
    
    LL f(int &m, int l, int r, int p, vector<vector<vector<LL>>> &dp, vector<int> &req) {
        if(l == 0 && r == m - 1) {
            return 0;
        }

        if(dp[l][r][p] != -1) return dp[l][r][p];
        
        int current_floor = (p == 0) ? req[l] : req[r];
        int waiting = m - (r - l + 1);
        
        LL min_cost = 1e18; 

        if (l > 0) {
           LL dist = current_floor - req[l - 1]; 
           LL cost = dist * waiting; 
          
           min_cost = min(min_cost, cost + f(m, l - 1, r, 0, dp, req));
        }

        
        if (r < m - 1) {
            LL dist = req[r + 1] - current_floor; 
            LL cost = dist * waiting;
            min_cost = min(min_cost, cost + f(m, l, r + 1, 1, dp, req));
        }
        
      
        return dp[l][r][p] = min_cost;
    }
    
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        requests.push_back(start);
        sort(requests.begin(), requests.end());

        int m = requests.size(); 
        
        vector<vector<vector<LL>>> dp(m, vector<vector<LL>>(m, vector<LL>(2, -1)));

        int si = lower_bound(requests.begin(), requests.end(), start) - requests.begin();

        return f(m, si, si, 0, dp, requests);
    }
};