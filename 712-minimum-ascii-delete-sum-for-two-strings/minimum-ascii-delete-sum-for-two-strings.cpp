class Solution {
public:
//here we need to maximise the ascii sum of the common subseq we choose so here we arent asked about min operation to make two string equal which would have meant to turn those two string into their lcs , here we turn them into a subseq with max ascii value no matter if its lcs or not since we arent told any minimum operation thing , just lowest ascii sum of deleted chars. for eg in a case lcs would be aaaaa with a value of 452 but a smaller subseq like zzzz has 458 ie more ascii value but not lcs , so we go for zzzz.

    int n;
    int m;

    int ascii(string &s) {
        int sum = 0;
        for(char c : s) sum += c;
        return sum;
    }

//this f means max ascii of any common subseq btw s1 and s2
    int f(int i , int j , string &s1, string &s2 , vector<vector<int>> &dp){
        if(i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
//agr koi bhi char match kr rha , toh usko lelo since all chars have +ve ascii value so koi harm nhi hai and for eg lets say we skip this char and we got an answe say zbc now kyuki yeh wala char obv zbc ke pehle aaya toh this char + zbc would be a vaid and correct answer. that's why there should be no doubt in blindly taking the char which match will be in the ans for the current subproblem f(i , j).

            return (int)s1[i] + f(i + 1 , j+1 , s1 , s2 , dp) ;      
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