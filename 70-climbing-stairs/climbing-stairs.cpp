class Solution {
public:
    int f(int i, int n, vector<int> &dp){
        if(i == n) return 1;     // reached destination that is cnt 1 valid path
        if(i > n) return 0;      // crossed destination
        if(dp[i] != -1)
            return dp[i];

        return dp[i] = f(i+1, n, dp) + f(i+2, n, dp);
    }

    int climbStairs(int n) {

    vector<int> dp(n+2,0);
//no need to mark anything further than n as 0 , our base vector is already 0 initialised. we took n+2 bcz suppose n=5 adn at i=4 we take 5 and 6 , so we need the 6th indx to prevent out of bounds hence 5+2=7 which measn it goes till 6th index.
    dp[n] = 1;
    for(int i=n-1;i>=0;i--)
    {
        dp[i] = dp[i+1] + dp[i+2];
    }

    return dp[0];
}
};
//to convert to table , think for dp[i] what states do I need , dpi+1 and dp i+2 , so we need these precalc , so we start forming table from n -> 0. mark base cases in the table
int climbStairs(int n) {

    vector<int> dp(n+2,0);
//no need to mark anything further than n as 0 , our base vector is already 0 initialised. we took n+2 bcz suppose n=5 adn at i=4 we take 5 and 6 , so we need the 6th indx to prevent out of bounds hence 5+2=7 which measn it goes till 6th index.
    dp[n] = 1;
    for(int i=n-1;i>=0;i--)
    {
        dp[i] = dp[i+1] + dp[i+2];
    }

    return dp[0];
}