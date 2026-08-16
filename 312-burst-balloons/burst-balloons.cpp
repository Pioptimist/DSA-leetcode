// class Solution {
// public:
//     int f(int i , int j , vector<int>& nums , vector<vector<int>>& dp){
//         if(i > j) return 0;

//         int maxi = INT_MIN;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         for(int k = i ; k <= j ; k++){
//             int coins = nums[i-1]*nums[k]*nums[j+1] + f(i , k-1 , nums , dp) + f(k+1 , j , nums , dp);
// //here the logic is instead of choosing first balloon , for every interval we choose whats the last balloon we can choose and from up there the recursion builds if we pop ith balloon last , then what coins we can get
//             maxi = max(maxi , coins);
//         }

//         return dp[i][j] = maxi;
//     }
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         nums.insert(nums.begin() , 1);
//         nums.push_back(1);

//         vector<vector<int>> dp(n+1 ,vector<int>(n+1, -1));

//         return f(1 , n , nums , dp);
        
//     }
// };

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Pad the array with 1s at both ends
        vector<int> padded(n + 2, 1);
        for (int i = 0; i < n; i++) {
            padded[i + 1] = nums[i];
        }
        
        int N = padded.size();
        
        // dp[i][j] = max coins from bursting balloons strictly in range [i...j]
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 2; i >= 1; i--) {
            
            // 
            for (int j = i; j <= N - 2; j++) {
                
                int maxi = INT_MIN;
                // k is the LAST balloon to burst in this range
                for (int k = i; k <= j; k++) {
                    int cost = dp[i][k - 1] + dp[k + 1][j] + 
                               (padded[i - 1] * padded[k] * padded[j + 1]);
                    
                    maxi = max(maxi, cost);
                }
                
                dp[i][j] = maxi;
            }
        }
        
        return dp[1][N - 2];
    }
};