class Solution {
public:
    int n;
    int m;
    // the crux of this question is if at current j , j+1 is * , then we take j
    // and j+1 or x* as one single char and try matching
    // bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
    //     if (i >= n && j >= m) {
    //         return true;
    //     }
    //     // else if((i >= n && j < m) || (i<n && j>=m)){
    //     //     return false;
    //     // }
    //     // the above commented base case which seems obv isnt true always bcz of
    //     // cases like s="" p="a*b*" here i==n and j < m but this will still give
    //     // a match since we can just skip a* and b* for an empty string match
    //     else if (i < n && j >= m) {
    //         return false;
    //     } 
    //     else if (i >= n && j < m) {
    //         if (j + 1 < m && p[j + 1] == '*') {
    //             return f(i, j + 2, s, p,dp); // skip the x* and check again if the remaining p can match an empty string or not
    //         }
    //         return false; // if no x* , def return false
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (j + 1 < m && p[j + 1] == '*') {
    //         if (i < n && (s[i] == p[j] || p[j] == '.')) {
    //             return dp[i][j] = f(i + 1, j, s, p, dp)  ||  f(i, j + 2, s, p,dp);// match the chars but since x* can have more occur of x , we dont move j pointer or we dont match at all and skip x* ie we took 0 occurences
    //         }
            
    //         // even if s[i] doesnt match with x* , there is a chance we can skip
    //         // x* and match   s[i] ahead
    //         return dp[i][j] = f(i, j + 2, s, p, dp);
    //     } else {
    //         if (i < n && (s[i] == p[j] || p[j] == '.')) {
    //             return dp[i][j] = f(i + 1, j + 1, s, p, dp);
    //         }
    //         return false; // clear mismatch
    //     }
    // }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();

        // vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

        // return f(0 , 0 , s , p , dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        dp[n][m] = 1; // mark true when both string exhausted

        for (int i = 0; i < n; i++) {
            dp[i][m] = 0; // mark false when p exhausted but s isnt
        }

        for (int j = m - 1; j >= 0; j--) { // can the remaining pattern p match empty string s

            if (j + 1 < m && p[j + 1] == '*')
                dp[n][j] = dp[n][j + 2];

            else
                dp[n][j] = false;
        }

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >=0 ; j-- ){
                    
                if( j + 1 < m && p[j+1] == '*'){
                    if(i < n && (s[i] == p[j] || p[j] == '.')){
                        dp[i][j] = dp[i + 1][j] || dp[i][j+2];
                    }

                    else{
                        dp[i][j] = dp[i][j+2];
                    }

                }
                else{
                    if (i < n && (s[i] == p[j] || p[j] == '.')) {
                       dp[i][j] = dp[i + 1][j + 1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }

            }
        }

        return dp[0][0];

    }
};
