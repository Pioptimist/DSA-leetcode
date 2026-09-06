// class Solution {
// public:
//     bool checkPartitioning(string s) {
//         int n = s.size();
        
//         // dp[i] will store the minimum cuts needed for the prefix s[0...i-1]
//         vector<int> dp(n + 1);
        
//         // Base case initialization: 
//         for (int i = 0; i <= n; i++) {
//             dp[i] = i - 1;
//         }
        
//         for (int i = 0; i < n; i++) {
//             // 1. Expand odd-length palindromes (center is a single character)
//             int left = i, right = i;
//             while (left >= 0 && right < n && s[left] == s[right]) {

//                 dp[right + 1] = min(dp[right + 1], dp[left] + 1);
//                 left--;
//                 right++;
//             }
            
//             // 2. Expand even-length palindromes (center is between two characters)
//             left = i;
//             right = i + 1;
//             while (left >= 0 && right < n && s[left] == s[right]) {
//                 dp[right + 1] = min(dp[right + 1], dp[left] + 1);
//                 left--;
//                 right++;
//             }
//         }
        
//         return dp[n] == 2;
//     }
// };

// why this code will fail ? bcz in this we are finding the min cuts needed to make eac partiotion a palindrome , consider bbab , our algo will return dp[n ] as 1 bcz a | bab but acc to this ques we can do bb | a | b

// to solve this ques we just need to know if we can make s[0..i] , s[i+1....j] , s[j+1....n-1] palindromes for any i or j

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        
        for (int i = 0; i < n; i++) {
            // Odd length palindromes
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                isPal[l][r] = true;
                l--; r++;
            }
            
            //even len
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                isPal[l][r] = true;
                l--; r++;
            }
        }
        
    // now we know every s[i..j] which is a palindrome , now check for these three :  s[0..i] , s[i+1....j] , s[j+1....n-1]   
        for (int i = 0; i < n - 2; i++) {
            if (isPal[0][i]) {
                for (int j = i + 1; j < n - 1; j++) {
                    if (isPal[i + 1][j] && isPal[j + 1][n - 1]) {
                        return true; 
                    }
                }
            }
        }
        
        return false;
    }
};