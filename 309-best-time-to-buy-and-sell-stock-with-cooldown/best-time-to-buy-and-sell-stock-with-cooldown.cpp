class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+2 , vector<int> (2 , 0));
        for(int i = n-1 ; i>=0 ; i--){
            for(int b = 0 ; b <=1 ; b++){
                if(b==1){
                    dp[i][b] = max(-p[i] + dp[i+1][0] , 
                                   0 + dp[i+1][b]);
                }
                else{
                    dp[i][b] = max(p[i] + dp[i+2][1] , 
                                   0 + dp[i+1][0]);
                }
            }
        }

        return dp[0][1];
        
    }
};