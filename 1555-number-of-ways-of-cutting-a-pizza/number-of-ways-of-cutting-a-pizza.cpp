class Solution {
public:
    long long mod= 1e9 + 7;
    int f(int i , int j , int k, int n , int m, vector<vector<int>> &apples, vector<vector<vector<int>>> &dp){
        if(apples[i][j] < k) return 0;

        if(k == 1){
            if(apples[i][j] >=k) return 1;

            return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        long ans = 0;
        for(int h = i+1 ; h < n ; h++){
            int lower = apples[h][j];
            int upper = apples[i][j] - lower;
            if(upper >= 1 && lower >= k-1){
                ans = (ans%mod + f(h , j , k-1 , n , m , apples, dp)%mod)%mod;
            }
        }
        for(int v = j+1 ; v < m ; v++){
            int right = apples[i][v];
            int left = apples[i][j] - right;
            if(left >= 1 && right >= k-1){
                ans = (ans%mod + f(i , v , k-1 , n , m , apples , dp)%mod)%mod;
                
            }
        }

        return dp[i][j][k] = ans%mod;
    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();

        vector<vector<int>> apples(n+1 , vector<int>(m+1 , 0));
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(m+1 , vector<int>(k+1 , -1)));

        for(int i = n-1 ; i>= 0 ;i--){

            for(int j = m-1; j>=0 ; j--){

                // apples[i][j] = apples[i][j+1];
                // for(int l = i ; l < n;l++){
                //     if(pizza[l][j] == 'A'){
                //         apples[i][j]++;
                //     }
                // }
                apples[i][j] = (pizza[i][j] == 'A')
                             + apples[i+1][j]
                             + apples[i][j+1]
                             - apples[i+1][j+1];

            }
        }

        return f(0 , 0 , k , n , m, apples , dp);
        
    }
};