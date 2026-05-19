class Solution {
public:
    vector<vector<int>> dp;
    int f(int n , int d , int i , vector<int>& job){
        if( d == 1){
            int maxi = INT_MIN;
            for(int j = i ; j < n ; j++){
                maxi = max(maxi , job[j]);
            }
            return maxi;
        }
        if(dp[i][d] != -1) return dp[i][d];
        int maxi = INT_MIN;
        int finalRes = INT_MAX;
        //we need to make sure future walo ke liye d - 1 jobs rhe kyuki hr din atleast 1 job unko krna hai , mtlb ek din mein at max n - d + 1, or at indx n-d
        for(int k = i ; k <= n - d ; k++){
            maxi = max(maxi , job[k]);

            int res = maxi + f(n , d-1 , k+1 , job);
            finalRes = min(finalRes , res);

        }

        return dp[i][d] = finalRes;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        dp.resize(n, vector<int>(d + 1, -1));
        if(n < d) return -1;
        return f( n , d , 0 , jobDifficulty);
        
    }
};