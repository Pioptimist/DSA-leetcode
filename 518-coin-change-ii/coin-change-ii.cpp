class Solution {
public:
    int f(int i , int t , vector<vector<int>> &dp, vector<int>& coins){
        if(t == 0) return 1;
        if(i == 0){
            if(t % coins[i] == 0 && coins[i] != 0) return dp[i][t] = 1;
            else{
                return 0;
            }
        }

        if(dp[i][t] != -1) return dp[i][t];
        int notT = f(i-1 , t , dp , coins);
        int take = 0;
        if(coins[i]<=t){
            take = f(i , t - coins[i], dp , coins);
        }

        return dp[i][t] = take + notT;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));

        long res = f(n-1 , amount , dp , coins);        
        return res;
        
    }
};