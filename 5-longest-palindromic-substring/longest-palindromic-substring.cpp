class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxlen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // Check odd length palindromes (single char center)
            int len1 = expand(s, i, i);
            // Check even length palindromes (two char center)
            int len2 = expand(s, i, i + 1);
            
    
            int current_max = max(len1, len2);
            
            if (current_max > maxlen) {
                maxlen = current_max;
                
                start = i - (current_max - 1) / 2; //try few tc like racecar to figure out the forumula .
            }
        }
        
        return s.substr(start, maxlen);
    }
    
private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1; 
    }
};


// class Solution {
// public:
//     int t[1001][1001];
// //simply check if every possible substr is a palindrome or not and when you do store there leng and starting index for that particular maxlen. then we can build it 
//     bool isPalindrome(string &s, int l, int r){
//         if(l >= r) 
//             return 1;

//         if(t[l][r] != -1){
//             return t[l][r];
//         }
//         if(s[l] == s[r]) {
//             return t[l][r] = isPalindrome(s, l+1, r-1);
//         }

//         return t[l][r] = false;
//     }
    
//     string longestPalindrome(string s) {
//         int n = s.length();
//         int maxlen = INT_MIN;
//         int startingIndex = 0;

//         memset(t, -1, sizeof(t));
//         for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
                
//                 if(isPalindrome(s, i, j)) {
//                     if(j-i+1 > maxlen){
//                         startingIndex = i;
//                         maxlen = j-i+1;
//                     }
//                 }
                
//             }
//         }
//         return s.substr(startingIndex, maxlen);
//     }
// };