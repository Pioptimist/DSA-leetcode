class Solution {
public:
    vector<vector<int>> dp;
    int m;
    int M = 1e9 + 7;

    int f(int i , int step){
        if( step == 0){
            if(i == 0 ) return 1; 
            return 0;
        }

        if(dp[i][step] != -1) return dp[i][step];

        long long left = (i - 1 >= 0) ? f(i - 1, step - 1) : 0;
        long long stay = f(i, step - 1);
        long long right = (i + 1 < m) ? f(i + 1, step - 1) : 0;

        long long res = (left + stay + right) % M;

        return dp[i][step] = res;
    }
    int numWays(int steps, int arrLen) {
        int n = steps;
        m = arrLen;
        dp.assign(n + 1 , vector<int> (n + 1 , -1));

        return f(0 , steps);
        
    }
};