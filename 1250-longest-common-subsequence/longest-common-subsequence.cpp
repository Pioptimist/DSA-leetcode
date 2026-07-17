class Solution {
public:
    int n;
    int m;

    int f(int i , int j , string &s1, string &s2 , vector<vector<int>> &dp){
        if( i== n || j == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + f(i+1 , j+1 , s1 , s2 , dp);
        }

        //agr upr wale se return nhi huya toh => no match , so try either i ko bdhao ya j ko

        return dp[i][j] = max( f(i+1 , j , s1 , s2 , dp) , f(i , j+1 , s1 , s2 , dp));


    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();

        vector<vector<int>> dp(n+1 , vector<int>(m , -1));

        return f(0 , 0 , text1 , text2 , dp) == -1 ? 0 : f(0 , 0 , text1 , text2 , dp);
        
    }
};