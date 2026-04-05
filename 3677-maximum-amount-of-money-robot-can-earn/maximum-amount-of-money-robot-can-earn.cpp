// class Solution {
// public:
//     long f(int i, int j, int n, int m, vector<vector<int>>& coins, int k,
//     vector<vector<vector<int>>> &dp) {

//         // out of bounds
//         if(i >= n || j >= m) return INT_MIN;

//         // destination
//         if(i == n-1 && j == m-1) {
//             if(coins[i][j] < 0 && k < 2) return 0; // skip it
//             return dp[i][j][k] = coins[i][j];
//         }

//         if(dp[i][j][k] != -1) return dp[i][j][k];

//         long val = coins[i][j];
//         long right = INT_MIN, down = INT_MIN;

//         if(val >= 0) {
//             right = val + f(i, j+1, n, m, coins, k , dp);
//             down  = val + f(i+1, j, n, m, coins, k , dp);
//         }
//         else {
//             //  take negative
//             long takeR = val + f(i, j+1, n, m, coins, k , dp);
//             long takeD = val + f(i+1, j, n, m, coins, k , dp);

//             // option 2: skip negative (if possible)
//             long skipR = INT_MIN, skipD = INT_MIN;
//             if(k < 2) {
//                 skipR = f(i, j+1, n, m, coins, k+1 , dp);
//                 skipD = f(i+1, j, n, m, coins, k+1 , dp);
//             }

//             right = max(takeR, skipR);
//             down  = max(takeD, skipD);
//         }

//         return dp[i][j][k] = max(right, down);
//     }

//     int maximumAmount(vector<vector<int>>& coins) {
//         int n = coins.size();
//         int m = coins[0].size();
//         vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(m+1 , vector<int>(3 , -1)));
//         return f(0, 0, n, m, coins, 0 , dp);
//     }
// };

class Solution {
public:
    int m;
    int n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && neu > 0) {
                return 0; //neutralize kardiya robber ko
            }

            return coins[i][j];
        }

        if(i >= m || j >= n) {
            return INT_MIN;
        }

        if(t[i][j][neu] != INT_MIN) {
            return t[i][j][neu];
        }

        //Take the current cell value
        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));

        //Skip current value if you can
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};