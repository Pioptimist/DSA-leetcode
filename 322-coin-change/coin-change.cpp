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
        // vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        // long res = f(n-1 , amount , dp , coins);
        // if(res == 1e9) return -1;
        
        // return res;
        // check out striver 0/1 knapsack for 1 d optimisation , here we go forward bcz we are allowed to reuse a coin or state
        vector<int> dp(amount + 1 , 1e9);
        for(int t = 0 ; t <= amount ; t++){
            if(t % coins[0] == 0 && coins[0]!=0) dp[t] = t/coins[0] ;
        }

        for(int i = 1 ; i < n ; i++){
            for(int t = 0 ; t <= amount ; t++){
                int notT = 0 + dp[t];
                int take = 1e9 ;
                if(coins[i] <= t && dp[t - coins[i]] != 1e9){
                    take = 1 + dp[t - coins[i]];
                }

                dp[t] = min(notT , take);
            }
        }
        return dp[amount] ==1e9 ? -1 : dp[amount];
        
    }
};