class Solution {
public:
    bool f(vector<int> &nums , int t , int ind, vector<vector<int>> &dp){
        if(t == 0) return dp[ind][t] = 1;
        if(ind == 0) return dp[ind][t] = (nums[ind] == t);

        if(dp[ind][t] != -1) return dp[ind][t];

        bool notT = f(nums , t , ind - 1, dp);
        bool take = 0;
        
        if(t > nums[ind]){
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

        return f(nums , t/2 , n-1 , dp);
        
    }
};