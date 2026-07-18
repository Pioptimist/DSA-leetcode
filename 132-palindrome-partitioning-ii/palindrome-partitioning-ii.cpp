class Solution {
public:
    int n;
    vector<vector<int>> pal;
    vector<vector<int>> dp;

    bool isPalindrome(int i, int j, string &s){ //s[i...j] wala palind hai ki nhi
        if(i >= j) return true;

        if(pal[i][j] != -1)
            return pal[i][j];

        if(s[i] == s[j])
            return pal[i][j] = isPalindrome(i+1, j-1, s);

        return pal[i][j] = false;
    }

    // start = beginning of current partition
    // end   = current position we are extending to
    int f(int start, int end, string &s){

        if(end == n){
            if(isPalindrome(start, end-1, s))
                return 0;      // last partition is valid
            return 1e9;
        }

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = 1e9;

        // Option 1 : Keep extending current substring
        ans = f(start, end+1, s);

        // Option 2 : Cut here if current substring is palindrome
        if(isPalindrome(start, end, s)){
            ans = min(ans, 1 + f(end+1, end+1, s));
        }

        return dp[start][end] = ans;
    }

    int minCut(string s) {
        n = s.size();

        pal.assign(n, vector<int>(n, -1));
        dp.assign(n+1, vector<int>(n+1, -1));

        return f(0,0,s);
    }
};