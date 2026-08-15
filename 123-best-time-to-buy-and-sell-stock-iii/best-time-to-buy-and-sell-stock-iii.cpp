// class Solution {
// public:
// //must sell the stocks before we buy so again cant hold more than one share at a time.
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         vector<vector<vector<int>>> dp(
//             n+1, vector<vector<int>>(2, vector<int>(3, 0))   // taking all elements 0 covers base cases
//         );

//         for(int i = n-1; i >= 0; i--){
//             for(int b = 0; b <= 1; b++){
//                 for(int c = 1; c <= 2; c++){   // c starts from 1 bcz when c == 0, we know thats a base case

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

//         return dp[0][1][2];
//     }
// };


// for(int i = 0 ; i< n ; i++){ for(int b = 0 ; b < 2 ; b++){ dp[i][b][0] = 0; //base case } } ie number of transactions is satisfied , no more buy 
// for(int b = 0 ; b< 2 ; b++){ for(int c = 0 ; c<3 ; c++){ dp[n][b][c] = 0; //base case } ie out of bounds chle gye toh fir aur kuch nhi kr skte


//optimised code for space , notice our dp[i] only ever depends on dp[i+1] so we dont need a big ass vector to hold all this data , we can use two small vectors and do this 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // 'ahead' represents dp[i+1]
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        // 'curr' represents dp[i]
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int i = n-1; i >= 0; i--){
            for(int b = 0; b <= 1; b++){
                for(int c = 1; c <= 2; c++){   
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

        return ahead[1][2];
    }
};