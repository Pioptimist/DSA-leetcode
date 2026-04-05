class Solution {
public:
    int MOD = 1e9 + 7;
    long long f(string &target , int i , int j, vector<vector<int>> &freq, 
    int n , int k, vector<vector<int>> &dp){

        if( i == n) return 1;
        if( j == k) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        long long notT = f( target , i , j + 1 , freq , n , k , dp);
        long long ch = target[i] - 'a';
        long long take = 0;

        if(freq[ch][j] > 0){
            take = (freq[ch][j] * f(target, i+1, j+1, freq, n, k , dp)) % MOD;
        }

        return dp[i][j] = (take + notT) % MOD;


    }
    int numWays(vector<string>& words, string target) {
        int n = target.size();
        int k = words[0].size();
        vector<vector<int>> freq(26, vector<int>(k, 0));
        for(int idx = 0; idx < k ; idx++){
            for(string &st : words){
                char ch = st[idx];
                freq[ch - 'a'][idx]++;
            }
        }
        vector<vector<int>> dp(n+1 , vector<int>(k+1, -1));
        return f(target , 0 , 0 , freq , n , k , dp);
        
    }
};