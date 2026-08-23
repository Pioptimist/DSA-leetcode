// class Solution {
// public:
//     int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
//         int n = s1.size();
//         int m = s2.size();

//         if(i == n) return m - j;   //means s1 empty ho chuka aur s2 is remaining ie empty string ko bache hue s2 ke string ke saath match ke liye number of operations needed => m-j insert operations , for eg turn "" to "ro" , we would obv need 2 insert op

//         if(j == m) return n - i;   //means s2 exhausted mtlb s1 rh gya and s2 is completely matched in s1 , for eg "hrose" "rose" , and this base case suggest we matched rose so what remains is "h" and "" , so to convert a string to empty string => delete the remining chars

//         if(dp[i][j] != -1) return dp[i][j];

//         // match
//         if(s1[i] == s2[j]) {
//             return dp[i][j] = f(i+1, j+1, s1, s2, dp); //match kr gya toh dont do nothing
//         }

//         //only when mismatches , try to do the bottom three operation
//         int del = 1 + f(i+1, j, s1, s2, dp);     //we deleted a char in s1 ie ki iss char ko delete krke aage dekho ki shyd jth char match ho jaye

//         int ins = 1 + f(i, j+1, s1, s2, dp);     //we inserted a char before ith char to match with jth char , so obv i will remain where it was for future matching

//         int rep = 1 + f(i+1, j+1, s1, s2, dp);   //char replacement so both chars matched and goes ahead  

//         return dp[i][j] = min({del, ins, rep});
//     }

//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return f(0, 0, word1, word2, dp);
//     }
// };

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++) dp[n][j] = m - j;
        for (int i = 0; i <= n; i++) dp[i][m] = n - i;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int del = 1 + dp[i + 1][j];
                    int ins = 1 + dp[i][j + 1];
                    int rep = 1 + dp[i + 1][j + 1];

                    dp[i][j] = min({del, ins, rep});
                }
            }
        }

        
        return dp[0][0];
    }
};