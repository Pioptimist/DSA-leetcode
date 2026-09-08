// class Solution {
// public:
//     int n;
//     vector<vector<int>> pal;
//     vector<int> dp;

//     // bool isPalin(const string &s){ // too expensive as we are doing s.substr and then this check so overall tc ~ O(n3) , either find every possible palindrome earlier or use recusion with memo for isPalind
//     //     int i = 0; 
//     //     int j = s.size() - 1;
//     //     while(i <=j){
//     //         if(s[i] != s[j]) return false;
//     //         i++;
//     //         j--;
//     //     }
//     //     return true;
//     // }
//     int f(int i , string &s){
//         if(i >= n){
//             return 0; // no partition possible
//         }
        
//         if(dp[i] != -1) return dp[i];
//         int ans = 1e9;

//         for(int end = i ; end < n ; end++){
//             if(isPalin(s.substr(i , end - i + 1 ))){
//                 ans = min(ans , 1 + f(end+1 , s));
//             }
//         }

//         return dp[i] = ans;
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


// we will many a times see this error  error: non-const lvalue reference to type 'basic_string<...>' cannot bind to a temporary of type 'basic_string<...>' => it simply means string &s will take a normal modificable string but thing is s.substr returns a temp string obj which we cannot modify hence the compiler throws an error saying use const or remove & as we cant modify the substr .