class Solution {
public:
    int f(int i , int t , vector<vector<int>> &dp, vector<int>& coins){
        if(i == 0){
            if(t % coins[i] == 0 && coins[i] != 0) return dp[i][t] = t/coins[i];
            else{
                return 1e9;
            }
        }

        if(dp[i][t] != -1) return dp[i][t];
        int notT = 0 + f(i-1 , t , dp , coins);
        int take = 1e9;
        if(coins[i]<=t){
            take = 1 + f(i , t - coins[i], dp , coins);
        }

        return dp[i][t] = min(take,notT);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        long res = f(n-1 , amount , dp , coins);
        if(res == 1e9) return -1;
        
        return res;
        
    }
};