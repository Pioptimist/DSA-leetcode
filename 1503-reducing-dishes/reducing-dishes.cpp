class Solution {
public:
    int f(vector<int>& s ,  int i , int t , vector<vector<int>> &dp , int n){
        if(i>=n) return 0;
        if(dp[i][t] != -1) return dp[i][t];
        int inc = s[i]*t + f(s , i + 1 , t + 1 , dp , n);
        int exc =  f(s , i + 1 , t , dp , n);

        return dp[i][t] = max(inc , exc);


    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(begin(satisfaction) , end(satisfaction));

        vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));

        return f(satisfaction , 0 , 1, dp , n);
    }
};