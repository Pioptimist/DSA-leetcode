class Solution {
public:
    int dp[1001][2001];

    int f(vector<vector<int>>& piles, int k, int n, int i){
        if(i == n || k == 0) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int notTake = f(piles, k, n, i+1);

        int take = 0, sum = 0;

        for(int j = 0; j < piles[i].size() && j < k; j++){
            sum += piles[i][j];
            take = max(take, sum + f(piles, k-(j+1), n, i+1));
        }

        return dp[i][k] = max(take, notTake);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();
        return f(piles, k, n, 0);
    }
};
// class Solution {
// public:
//     int f(vector<vector<int>>& piles, int i, int j, int k){
//         if(i == piles.size() || k == 0) return 0;

//         if(j == piles[i].size()){
//             return f(piles, i+1, 0, k); // move to next pile
//         }

//         // take coin
//         int take = piles[i][j] + f(piles, i, j+1, k-1);

//         // skip entire pile
//         int skip = f(piles, i+1, 0, k);

//         return max(take, skip);
//     }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         int n = piles.size();

//         return f(piles, 0, 0, k);
        
//     }
// };