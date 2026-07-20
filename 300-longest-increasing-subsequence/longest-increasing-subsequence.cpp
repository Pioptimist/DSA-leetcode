class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1);

        for(int i = 0 ; i < n ; i ++){
            for(int p = 0 ; p <= i-1 ; p++){
                if(nums[p] < nums[i]){
                    dp[i] = max(1 + dp[p] , dp[i]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
        
    }
};