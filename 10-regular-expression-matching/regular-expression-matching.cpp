class Solution {
public:
    int n;
    int m;

    bool f(int i , int j , string &s , string &p , vector<vector<int>> &dp){
        if(i >= n && j >= m){
            return true;
        }
        // else if((i >= n && j < m) || (i<n && j>=m)){
        //     return false;
        // }
//the above base case which seems obv isnt true alwas bcz of cases like s="" p="a*b*" here i==n and j < m but this will still give a match
        else if(i<n && j>=m){
            return false;
        }
        else if (i >= n && j < m){
            if(j + 1 < m && p[j + 1] == '*'){
                return f(i , j+2 , s , p , dp);  //skip the x* and check again if the remaining p can match an empty string or not
            }
            return false; //if no x* , def return false
        }
        if(dp[i][j] != -1) return dp[i][j];

        if (j + 1 < m && p[j + 1] == '*'){
            if( i < n && (s[i] == p[j] || p[j] == '.')){
                return dp[i][j] = f(i+1 , j , s , p ,dp) || f(i , j+2 , s , p , dp);
            }
            //even if s[i] doesnt match with * , there is a chance we can skip * and match s[i]
            return dp[i][j] = f(i , j+2 , s , p , dp);
        }
        else{
            if (i < n && (s[i] == p[j] || p[j] == '.')){
                return dp[i][j] = f(i+1 , j+1 , s , p , dp);
            }
            return false;
        }

    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();

        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

        return f(0 , 0 , s , p , dp);
        
    }
};