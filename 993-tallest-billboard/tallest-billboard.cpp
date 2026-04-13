class Solution {
public:
    int n ;
    vector<vector<int>> dp;

    int f(vector<int>& rods,int i , int diff){
        if(i >= n){
            if(diff == 0){
                return 0;
            }
            return INT_MIN; //prune
        }
        
        if(dp[i][diff + 5000] != -1) return dp[i][diff + 5000];
        int nothing =  f(rods , i+1 , diff);
        int l1 = rods[i] + f(rods , i+1 , diff + rods[i]);
        int l2 = rods[i] + f(rods , i+1 , diff - rods[i]);

        return dp[i][diff + 5000] = max({nothing , l1 , l2});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        dp.assign(n, vector<int>(10003, -1));

        return f(rods , 0 , 0)/2 ;


        
    }
};