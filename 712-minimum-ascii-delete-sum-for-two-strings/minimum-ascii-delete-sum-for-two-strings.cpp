class Solution {
public:
//simple ques of common subseq with max ascii val , one might think ki ans always lcs hi hoga but consider s1 = zzzzaaaaa and s2 = aaaaazzzz , lcs = aaaaa but subseq woth max ascii is zzzz, therefore we only focus on wt of every char we pick in our common subseq , the subseq with maxwt is our ans

    int n;
    int m;

    int ascii(string &s) {
        int sum = 0;
        for(char c : s) sum += c;
        return sum;
    }


    int f(int i , int j , string &s1, string &s2 , vector<vector<int>> &dp){
        if(i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){

            return dp[i][j] = (int)s1[i] + f(i + 1 , j+1 , s1 , s2 , dp) ;      
        }

        return dp[i][j] = max(f(i+1 , j , s1 ,s2 , dp) , f(i , j+1 , s1 , s2 , dp));

    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();

        vector<vector<int>> dp(n , vector<int>(m , -1));
        int cs = 0;
        cs = f(0 , 0 , s1 , s2 , dp);

        return ascii(s1) + ascii(s2) - (2*cs);
      
    }
};


