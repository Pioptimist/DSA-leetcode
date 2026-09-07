// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();

//         vector<vector<vector<int>>> dp(
//             n+1, vector<vector<int>>(2, vector<int>(k+1, 0))   // taking all elements 0 covers base cases
//         );

//         for(int i = n-1; i >= 0; i--){
//             for(int b = 0; b <= 1; b++){
//                 for(int c = 1; c <= k; c++){   // c starts from 1 bcz 0 is covered in base case

//                     if(b){
//                         dp[i][b][c] = max(
//                             -prices[i] + dp[i+1][0][c],
//                             dp[i+1][1][c]
//                         );
//                     }
//                     else{
//                         dp[i][b][c] = max(
//                             prices[i] + dp[i+1][1][c-1],
//                             dp[i+1][0][c]
//                         );
//                     }
//                 }
//             }
//         }

//         return dp[0][1][k]; //obv dp[0][1][k] bcz we are going reverse so at i = 0 , canb = 1 and  k= k
        
//     }
// };


class Solution {
public:
    int maxProfit(int k , vector<int>& prices) {
        int n = prices.size();

        // 'ahead' represents dp[i+1]
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        // 'curr' represents dp[i]
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int b = 0; b <= 1; b++){
                for(int c = 1; c <= k; c++){   
                    if(b){
                        curr[b][c] = max(-prices[i] + ahead[0][c], ahead[1][c]);
                    }
                    else{
                        curr[b][c] = max(prices[i] + ahead[1][c-1], ahead[0][c]);
                    }
                }
            }
            // Move our current day's calculations into the 'ahead' position 
            // for the next backward iteration
            ahead = curr; 
        }

        return ahead[1][k];
    }
};