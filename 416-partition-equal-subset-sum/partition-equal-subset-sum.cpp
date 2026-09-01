class Solution {
public:
    bool f(vector<int> &nums , int t , int ind, vector<vector<int>> &dp){
        if(t == 0) return dp[ind][t] = 1;
        if(ind == 0) return dp[ind][t] = (nums[ind] == t);

        if(dp[ind][t] != -1) return dp[ind][t];

        bool notT = f(nums , t , ind - 1, dp);
        bool take = 0;

        if(t >= nums[ind]){
            take = f(nums , t - nums[ind] , ind - 1 , dp);
        }

        return dp[ind][t] = notT || take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int t = 0;
        for(int i =0;i< n; i++){
            t += nums[i];
        }
        vector<vector<int>> dp(n+1 , vector<int>(t/2 + 1 , -1));
        if(t % 2 != 0) return false;  //if sum is odd , cant divide in 2 halves

        // return f(nums , t/2 , n-1 , dp);

        vector<bool> prev(t/2 + 1 , 0) , curr(t/2 + 1 , 0);
// we can see in our state that we only depend upon i - 1 , ie in bottom up dp , the prev row , so instead of 2d vector , we can keep two 1d vectors only
        prev[0] = 1;  
        curr[0] = 1;  // for target 0 , any case is gonna be true
        if (nums[0] <= t/2) {
            prev[nums[0]] = 1;
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= t/2 ; j++){  // j is for the target
                bool notT = prev[j];
                bool take = false;
                if(nums[i] <= j){
                    take = prev[j - nums[i]];
                }

                curr[j] = take | notT;
            }
            prev = curr;
        }

        return curr[t/2];
        
    }
};