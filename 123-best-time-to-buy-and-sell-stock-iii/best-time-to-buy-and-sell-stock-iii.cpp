class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0))   // taking all elements 0 covers base cases
        );

        for(int i = n-1; i >= 0; i--){
            for(int b = 0; b <= 1; b++){
                for(int c = 1; c <= 2; c++){   // c starts from 1

                    if(b){
                        dp[i][b][c] = max(
                            -prices[i] + dp[i+1][0][c],
                            dp[i+1][1][c]
                        );
                    }
                    else{
                        dp[i][b][c] = max(
                            prices[i] + dp[i+1][1][c-1],
                            dp[i+1][0][c]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};


// for(int i = 0 ; i< n ; i++){ for(int b = 0 ; b < 2 ; b++){ dp[i][b][0] = 0; //base case } } for(int b = 0 ; b< 2 ; b++){ for(int c = 0 ; c<3 ; c++){ dp[n][b][c] = 0; //base case }