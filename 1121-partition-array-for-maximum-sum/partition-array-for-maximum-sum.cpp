class Solution {
public:
    int f(int i , int n , int k , vector<int>& arr , vector<int> &dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        int len = 0 , maxel = INT_MIN;
        int maxi = INT_MIN;
        for(int j = i ; j < min(n , i + k) ; j++){
            len ++;
            maxel = max(maxel , arr[j]);
            int ans = maxel*len + f(j + 1 , n , k , arr , dp);

            maxi = max(ans , maxi);
        }

        return dp[i] = maxi;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n , -1);

        return f(0 , n , k , arr , dp);
        
    }
};