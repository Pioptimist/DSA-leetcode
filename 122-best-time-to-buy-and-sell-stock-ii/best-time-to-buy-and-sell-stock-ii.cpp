class Solution {
public:
//this ques says we can buy and sell multiple times a day but we can only hold one share at a time , ab khud socho for eg we buy at 1 , now we sell at 5 and again buy at 5 so it goes -1 + 5 - 5 => -1 ie it quals to skipping 5
//same thing when we buy and sell at the same day , 5 pe khareeda and 5 pe sell , netprofit 0 , so it is equal to skipping 5 altogether
    int n;
    
    int f(int i, bool canB , vector<int>& prices , vector<vector<int>> &dp){
        if(i == n) return 0;  //ya toh humne prev kuch buy kiya hoga , ab toh usse profit nhi aayega kyuki nothing to sell at , so return 0 ya fir kuch nhi buy kiya hoga toh then obv return 0

        if(dp[i][canB] != -1) return dp[i][canB];

        if(canB){
            int buy = -prices[i] + f(i+1 , 0 , prices , dp);

            int skip = f(i + 1 , 1 , prices , dp);

            return dp[i][canB] = max(buy , skip);
        }
        else{
            int sell = prices[i] + f(i+1 , 1 , prices , dp);

            int skip = f(i+1 , 0 , prices , dp);

            return dp[i][canB] = max(sell , skip);
        }
    }
    int maxProfit(vector<int>& prices) {

        // int max = 0;
        // int start = prices[0];
        // int len = prices.size();
        // for(int i = 1;i<len; i++){
        //     if(start < prices[i]){
        //         max += prices[i] - start;
        //     }
        //     start = prices[i];
        // }
        // return max;   //greedy method

        n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));

        return f(0 , 1 , prices , dp);
    }
};