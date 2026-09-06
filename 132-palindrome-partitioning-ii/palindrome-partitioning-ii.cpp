// class Solution {
// public:
//     int n;
//     vector<vector<int>> pal;
//     vector<int> dp;
// //normal partition  , keep making partion and check
//     bool isPalindrome(int i, int j, string &s){
//         if(i >= j) return true;
//         if(pal[i][j] != -1)
//             return pal[i][j];

//         if(s[i] == s[j]) return pal[i][j] = isPalindrome(i+1, j-1, s);

//         return pal[i][j] = false;
//     }

//     // f(start) = minimum partitions needed from index start 
//     int f(int start, string &s){

//         if(start == n)
//             return 0;

//         if(dp[start] != -1)
//             return dp[start];

//         int ans = 1e9;

//         // now we try extending the string till it's a palindrome and if its a palindrome try cutting it and recurse further
//         for(int end = start; end < n; end++){

//             if(isPalindrome(start,end,s)){ //to us the answer only matters when the current substr is a palindrome otherwise no valid answer
//                 ans = min(ans,1 + f(end+1,s));
//             }

//         }

//         return dp[start] = ans;
//     }

//     int minCut(string s) {
//         n = s.size();
//         pal.assign(n,vector<int>(n,-1));
//         dp.assign(n+1,-1);

//         return f(0,s) - 1;  //dry run this codee , the above func returns number of partition so for eg on "aab" ; aa | b it returns two since thee are two parts, hence we do -1.
//     }
// };



class Solution {
public:
//the idea for this idea is to expand from the centre of palindrome , and to do that we travel from left to right and store the min partition the string  0...i-1 in dp[i] , now suppose a substring we find is a palindrome ,so to store its length ie dp[right + 1] , we look at dp[left] and do a +1 bcz we are making another partition , for eg suppose xxxABAyyyy (x and y are abitrary) and left is at A and right is Y , we know this is a palindrome , so we do dp[right + 1] = dp[left] + 1, ie we are saying min partition upto left-1 and add 1 bcz of this palindrome.
    int minCut(string s) {
        int n = s.size();
        
        // dp[i] will store the minimum cuts needed for the prefix s[0...i-1]
        vector<int> dp(n + 1);
        
        // Base case initialization: 
        // Max cuts for a string of length 'i' is 'i - 1' (cutting every single character) hence we are storing that here as a start , dp[0] means cut needed for string of length 0 , here we are storing -1 bcz suppose the whole string is a palindrome then we say    dp[0] + 1 = 0 cuts needed for that string
        for (int i = 0; i <= n; i++) {
            dp[i] = i - 1;
        }
        
        for (int i = 0; i < n; i++) {
            // 1. Expand odd-length palindromes (center is a single character)
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                // Since s[left...right] is a palindrome, now the cuts needed for the string s[0....left - 1] = dp[left] , since s[l....r] is a palindrome we can the total partiontion including s[l....r] is dp[left] + 1 
                // now why dp[right + 1] ? bcz we know s[l....r] is a palind so min cuts till index r is dp[r + 1] , therefore we compare dp[r] with dp[l] + 1.
                
                dp[right + 1] = min(dp[right + 1], dp[left] + 1);
                left--;
                right++;
            }
            
            // 2. Expand even-length palindromes (center is between two characters)
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                dp[right + 1] = min(dp[right + 1], dp[left] + 1);
                left--;
                right++;
            }
        }
        
        return dp[n];
    }
};