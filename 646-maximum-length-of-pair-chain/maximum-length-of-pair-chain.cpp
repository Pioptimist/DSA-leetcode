class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        // this is like LIS with [a , b] [c , d]  where we are trying to se if b and c make an inc sequence or not

        int n = pairs.size();
        vector<int> dp(n , 1);
        sort(begin(pairs) , end(pairs));

        for(int i = 0 ; i < n ; i++){
            for(int p = 0 ; p < i ; p++){
                if(pairs[p][1] < pairs[i][0]){
                    dp[i] = max(dp[i] , 1 + dp[p]);
                }
            }
        }

        return *max_element(begin(dp) , end(dp));

    }
};