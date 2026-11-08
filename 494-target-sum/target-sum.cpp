class Solution {
public:
//logic here is we are asked to count subsets s1-s2 = d , now say s1 = d-s2 and s2 = total - s1 hence s1 = (total - target)/2 , therefore count all subsets which has sum equal to (total - target)/2
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int x : nums) total += x;

        if((total - target) < 0 || (total - target) % 2 != 0) return 0; //given nums[i] is >=0 so in no way subset sum can be <0 and also no decimal is possible so t - target has to be even.
        int k = (total - target) / 2;

        vector<vector<int>> dp(n , vector<int> (k+1 , 0));
        // for(int i = 0;i<n;i++) dp[i][0] = 1; //when remaining sum is 0 , we return 1 as there is always one to make a subset ie dont pick anything further => hence te 1

        if(nums[0] == 0) dp[0][0] = 2; //if nums[0] = 0 , there are two ways as we can pick this 0 and the sum wont be effected or we dont pick it and end the subset
        else dp[0][0] = 1; // else nums[0] != 0 , ie we dont pick hence 1

        if(nums[0] != 0 && nums[0] <= k)   dp[0][nums[0]] = 1; //if at ind =0 , remaining target is nums[0] only then we will def pick it => hence 1 . the nums[0]<= k is to prevent out of bounds
        
        for(int i = 1 ; i< n ; i++){
            for(int j = 0 ; j<=k ; j++){
                int notT = dp[i-1][j];
                int take = 0;
                if(nums[i]<= j){
                    take =  dp[i-1][j - nums[i]];
                }

                dp[i][j] = take + notT;
            }
        }

        return dp[n-1][k];

        
    }
};