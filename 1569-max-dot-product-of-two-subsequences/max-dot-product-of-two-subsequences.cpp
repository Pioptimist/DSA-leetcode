// class Solution {
// public:
//     int n , m;
//     vector<vector<int>> dp;

//     int f(int i , int j , vector<int>& nums1, vector<int>& nums2){
//         if(i == n || j == m){
//             return -1e9+7;
//         }
//         if(dp[i][j] != -1) return dp[i][j];

//         int val = nums1[i]*nums2[j];
//         int take_b = nums1[i]*nums2[j] + f(i+1, j+1 , nums1,nums2);
//         int take_i = f(i , j+1 , nums1 , nums2);
//         int take_j = f(i+1 , j , nums1 , nums2);

//         return dp[i][j] = max({val , take_b, take_i , take_j});
//     }
//     int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         n = nums1.size();
//         m = nums2.size();

//         dp.assign(n+1 , vector<int>(m+1 , -1));

//         return f(0 , 0 , nums1 , nums2);
        
//     }
// };

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MIN));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                long long prod = 1LL * nums1[i-1] * nums2[j-1];

                long long take = prod;

                // Only extend if valid
                if (dp[i-1][j-1] != LLONG_MIN) {
                    take = max(take, prod + dp[i-1][j-1]);
                }

                dp[i][j] = max({
                    take,
                    dp[i-1][j],
                    dp[i][j-1]
                });
            }
        }

        return dp[n][m];
    }
};