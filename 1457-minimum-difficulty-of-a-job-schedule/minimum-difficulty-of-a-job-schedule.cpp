// class Solution {
// public:
//     vector<vector<int>> dp;
//     int f(int n , int d , int i , vector<int>& job){
//         if( d == 1){
//             int maxi = INT_MIN;
//             for(int j = i ; j < n ; j++){
//                 maxi = max(maxi , job[j]);
//             }
//             return maxi;
//         }
//         if(dp[i][d] != -1) return dp[i][d];
//         int maxi = INT_MIN;
//         int finalRes = INT_MAX;
//         //we need to make sure future walo ke liye d - 1 jobs rhe kyuki hr din atleast 1 job unko krna hai , mtlb ek din mein at max n - d + 1, or at indx n-d
//         for(int k = i ; k <= n - d ; k++){
//             maxi = max(maxi , job[k]);

//             int res = maxi + f(n , d-1 , k+1 , job);
//             finalRes = min(finalRes , res);

//         }

//         return dp[i][d] = finalRes;
//     }
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         int n = jobDifficulty.size();
//         dp.resize(n, vector<int>(d + 1, -1));
//         if(n < d) return -1;
//         return f( n , d , 0 , jobDifficulty);
        
//     }
// };


class Solution {
public:

    int n;
    vector<vector<int>> dp;
    vector<int> suffixMax;

    int f(int i, int d, vector<int>& job) {

        // last day -> all remaining jobs must be done today
        if(d == 1)
            return suffixMax[i];

        if(dp[i][d] != -1)
            return dp[i][d];

        int currMax = INT_MIN;
        int ans = INT_MAX;

        // reserve at least (d-1) jobs for future days
        for(int k = i; k <= n - d; k++) {

            currMax = max(currMax, job[k]);

            ans = min(ans,
                      currMax + f(k + 1, d - 1, job));
        }

        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        n = jobDifficulty.size();

        if(n < d)
            return -1;

        dp.resize(n, vector<int>(d + 1, -1));

        // suffix maximum preprocessing
        suffixMax.resize(n);

        suffixMax[n - 1] = jobDifficulty[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffixMax[i] =
                max(jobDifficulty[i], suffixMax[i + 1]);
        }

        return f(0, d, jobDifficulty);
    }
};