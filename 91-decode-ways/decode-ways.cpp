class Solution {
public:
//while decoding we need to keep somethings in mind , we cant have a leading zer bcz that would be invalid  , next up is we cant take a three digit number , and next is if we are taking a two digit number we need to be sure that number is <=26 and >= 10 for a valid code
    
    int n;

    int f(int i , string &s , vector<int> &dp){
        if(i == n){
            return 1;
        }

        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0;
        
        //jo pehla number hai usko lelo 
        int fir = f(i+1 , s , dp);
        
        int sec = 0;
        //now build the second number and check if its valid or nah
        if(i + 1 < n){

           int num = (s[i]-'0')*10 + (s[i+1]-'0');

           if(num >= 10 && num <= 26)  sec = f(i+2,s,dp);
        }

        return dp[i] = fir + sec;

    }
    
    
    int numDecodings(string s) {

        n = s.size();
        vector<int> dp(n+1 , -1);

        return f(0 , s, dp);
        
    }
};