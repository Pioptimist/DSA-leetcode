class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // Check all odd-length palindromes (center is a single character at i)
            cnt += expand(s, i, i);
            
            // Check all even-length palindromes (center is between i and i+1)
            cnt += expand(s, i, i + 1);
        }
        return cnt;
    }
    
private:
    int expand(const string& s, int left, int right) {
        int local_cnt = 0;
        
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            local_cnt++;
            left--;     
            right++;     
        }
        
        return local_cnt;
    }
};


// class Solution {
// public:
//     int n;
// //here f means if s[i...j] is a palindrome or not
//     bool f(int i , int j , string &s , vector<vector<int>> &dp){
//         if(i > j) return true; //bcz when i>j ie hr char match ho chuka hai so just return true 
//         if(i == j) return dp[i][j] = true;

//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i] == s[j]){
//             return dp[i][j] = f(i+1 , j-1 , s, dp);
//         }

//         return dp[i][j] = false; //if no match then def this string is not a palindrome , no doubt in that.


//     }
//     int countSubstrings(string s) {
//         n = s.size();
//         vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));

//         for(int i = 0 ; i < n ; i++){  //create every possible substring and check if they are palindrome or not
//             for(int j = n-1 ; j >=i ; j--){
//                 f(i , j , s , dp);
//             }
//         }
//         //recurse over every possible interval ie substring and check whether they are palindrome or not and then cnt the ones which are and simply return ans

//         int cnt = 0;
//         for(int i = 0 ; i < n ; i++){
//             for(int j = 0 ; j < n ; j++){
//                 if(dp[i][j] == 1){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;

//     }
// };

