// class Solution {
// public:
//     int bestSum = 0;
//     vector<int> res;
//     vector<int> f(vector<int>& nums, int k, int n , int i , vector<int> &ans , int cnt , int currSum ){
        
//         if(cnt == 3){
//             if(currSum > bestSum){
//                 bestSum = currSum;
//                 res = ans;
//             }
//             return ans;
//         }
//         if(i == n){
//             return ans;
//         }
//         ans.push_back(i);
//         int currsum = 0;
//         if(i + k - 1 < n){
//             for(int j = i ; j< i+k ; j++){
//                 currsum += nums[j];
//             }
//             f(nums , k , n , i + k , ans , cnt+1 , currSum + currsum);   
//         }
        
//         ans.pop_back();
//         f(nums , k , n , i+1 , ans ,cnt, currSum);

//         return ans;


//     }
//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         f(nums , k , n , 0 , ans , 0 , 0);
//         return res;
        
//     }
// };

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> sub;

    int f(int i, int cnt, int k){
        if(cnt == 3) return 0;
        if(i >= n) return 0;

        if(dp[i][cnt] != -1) return dp[i][cnt];

        // skip
        int notTake = f(i+1, cnt, k);

        // take
        int take = 0;
        if(i + k <= n){
            take = sub[i] + f(i + k, cnt + 1, k);
        }

        return dp[i][cnt] = max(take, notTake);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        n = nums.size();

        // 🔥 Step 1: precompute subarray sums
        sub.assign(n, 0);
        int windowSum = 0;

        for(int i = 0; i < n; i++){
            windowSum += nums[i];
            if(i >= k) windowSum -= nums[i-k];
            if(i >= k-1) sub[i-k+1] = windowSum;
        }

        // 🔥 Step 2: DP
        dp.assign(n, vector<int>(4, -1));
        f(0, 0, k);

        // 🔥 Step 3: backtracking to get indices
        vector<int> res;
        int i = 0, cnt = 0;

        while(cnt < 3 && i < n){
            int notTake = f(i+1, cnt, k);

            int take = 0;
            if(i + k <= n){
                take = sub[i] + f(i + k, cnt + 1, k);
            }

            if(take >= notTake){
                res.push_back(i);
                i += k;
                cnt++;
            } else {
                i++;
            }
        }

        return res;
    }
};