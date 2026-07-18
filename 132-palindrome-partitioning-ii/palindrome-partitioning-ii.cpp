class Solution {
public:
    int n;
    vector<vector<int>> pal;
    vector<int> dp;

    bool isPalindrome(int i, int j, string &s){
        if(i >= j) return true;
        if(pal[i][j] != -1)
            return pal[i][j];

        if(s[i] == s[j]) return pal[i][j] = isPalindrome(i+1, j-1, s);
        
        return pal[i][j] = false;
    }

    // f(start) = minimum partitions needed from start to end
    int f(int start, string &s){

        if(start == n)
            return 0;

        if(dp[start] != -1)
            return dp[start];

        int ans = 1e9;

        // "Don't cut" is now this loop
        for(int end = start; end < n; end++){

            if(isPalindrome(start,end,s)){
                ans = min(ans,1 + f(end+1,s));
            }

        }

        return dp[start] = ans;
    }

    int minCut(string s) {
        n = s.size();
        pal.assign(n,vector<int>(n,-1));
        dp.assign(n+1,-1);

        return f(0,s)-1;
    }
};