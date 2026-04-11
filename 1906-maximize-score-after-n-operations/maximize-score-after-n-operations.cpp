// class Solution {
// public:
//     int f(vector<int>& nums, int n , vector<bool> vis, int op, 
//     unordered_map<vector<bool> , int> &dp){
//         int maxS = 0;
//         if(op > n) return 0;
//         if(dp.find(vis) != dp.end()) return dp[vis];

//         for(int i = 0 ; i < n-1; i++){
//             if(vis[i]== true) continue;

//             for(int j = i+1;j<n;j++){
//                 if(vis[j]== true) continue;

//                 vis[i] = true;
//                 vis[j] = true;
               
//                 int currS = op * __gcd(nums[i],nums[j]);
//                 int rem = f(nums , n  ,vis , op+1 , dp);
//                 maxS = max(maxS , currS + rem);

//                 vis[i] = false;
//                 vis[j] = false;

//             }
//         }
//         return dp[vis] = maxS;
//     }
//     int maxScore(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> vis(n , false);
//         unordered_map<vector<bool> , int> dp;
//         return f(nums , n ,vis , 1 , dp);
        
//     }
// };

class Solution {
public:
    int f(vector<int>& nums, int mask, int op, vector<int>& dp) {
        int n = nums.size();

        if(mask == (1 << n) - 1) return 0;

        if(dp[mask] != -1) return dp[mask];

        int maxScore = 0;

        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;

            for(int j = i + 1; j < n; j++) {
                if(mask & (1 << j)) continue;

                int newMask = mask | (1 << i) | (1 << j);

                int curr = op * __gcd(nums[i], nums[j]);

                int rem = f(nums, newMask, op + 1, dp);

                maxScore = max(maxScore, curr + rem);
            }
        }

        return dp[mask] = maxScore;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1 << n, -1);
        return f(nums, 0, 1, dp);
    }
};