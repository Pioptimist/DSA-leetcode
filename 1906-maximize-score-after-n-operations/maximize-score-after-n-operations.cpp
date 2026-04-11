class Solution {
public:
    int f(vector<int>& nums, int n , int i , int j, vector<bool> vis, int op, 
    unordered_map<vector<bool> , int> &dp){
        int maxS = 0;

        if(dp.find(vis) != dp.end()) return dp[vis];
        
        for(int i = 0 ; i < n-1; i++){
            if(vis[i]== true) continue;

            for(int j = i+1;j<n;j++){
                if(vis[j]== true) continue;

                vis[i] = true;
                vis[j] = true;
               
                int currS = op * __gcd(nums[i],nums[j]);
                int rem = f(nums , n , i , j+1 , vis , op+1 , dp);
                maxS = max(maxS , currS + rem);

                vis[i] = false;
                vis[j] = false;

            }
        }
        return dp[vis] = maxS;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n , false);
        unordered_map<vector<bool> , int> dp;
        return f(nums , n , 0 , 0 , vis , 1 , dp);
        
    }
};