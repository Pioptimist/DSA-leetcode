class Solution {
public:
    int N;
    int GOAL;
    int K;
    vector<vector<long>> dp;
    const int MOD = 1e9+7;
    
    long solve(int i, int j) {
        if(i == GOAL) {
            if(j == N)
                return 1;
            
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long result = 0;
        
        //Option-1 (Play a unique song)
        if(j < N)
            result += (N-j) * solve(i+1, j+1);
        
        //Option-2 (Replay a song)
        if(j > K)
            result += (j - K) * solve(i+1, j);
        
        
        return dp[i][j] = result % MOD;

    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        N    = n;
        GOAL = goal;
        K    = k;
        dp.assign(goal + 1, vector<long>(n + 1 , -1));
        return solve(0, 0); 
    }
};