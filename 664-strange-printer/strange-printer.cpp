class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int f(int l, int r, string& s){
        if(l == r)
            return 1; //single char ko print krne ka tareeka is only 1
        
        else if(l > r)
            return -1e9; //no way to print as empty string now
        
        if(dp[l][r] != -1)
            return dp[l][r];


        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;  //jb tk i matches char at l , keep going forward

        if(i == r+1)
            return 1; //mtlb hr ek char same hai lth char ke , toh we can print them in 1 go.

        int normal = 1 + f(i,r,s); //mtlb agr aabcdaa hai toh usko aa|bcdaa aise krke ans

        int aage_ka = INT_MAX;  //to overwrite print

        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = f(i,j-1,s) + f(j,r,s); // two things , imagine we are printing from l to j in one go by s[j] , so if we had abca , we need to fix bc as we just printed aaaa but one thing we do know is this first and last 'a' are correct , we dont need to fix that , hence f(i , j-1) ie tell me min cost to print this section of s[i....j-1] and f(j , r) . next thing is we didnt print anything here , we said agr hum l to j tk same char print krenge toh kya hoga thats why we did no 1 + f() + f() 
                
                aage_ka = min(aage_ka, x);
            }
        }

        return dp[l][r] = min(aage_ka, normal);
    }

    int strangePrinter(string s) {
        n = s.length() ;
        
        dp.resize(n,vector<int>(n+1, -1));
        
        return f(0, n-1, s);
    }
};

// //try dry running cases like aba , abcaa , abaca


// class Solution {
// public:
// //think of breaking into smaller and smaller subproblems like for aabca , we partition one by one so a|abca then aa|bca and so on , now imagine for a|a we get 1 + 1 = 2 but ince they are the same char we can print them in one go hence 2 - 1
// // now think abca i = 0 , j = n-1, jitne bhi times aya hoga ans since s[i] == s[j] , means we can print aaaa and we counted these two a two times which can be printed in once , so we do minturns - 1
//     int f(int i, int j, const string& s, vector<vector<int>>& dp) {
//         if (i == j) return 1;
//         if (dp[i][j] != -1) return dp[i][j];

//         int minTurns = INT_MAX;

//         for (int k = i; k < j; k++) {
//             minTurns = min(minTurns, f(i, k, s, dp) + f(k + 1, j, s, dp));
//         }

//         return dp[i][j] = (s[i] == s[j]) ? minTurns - 1 : minTurns;
//     }
//     int strangePrinter(std::string s) {
//         int n = s.length();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return f(0, n - 1, s, dp);
//     }
// };