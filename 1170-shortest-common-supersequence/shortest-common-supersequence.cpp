class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//the logic in here is ki superseq mein lcs toh hoga hi aur lcs ke alawa jo char bach gye , woh honge now the thing is ki jo char lcs mein nhi hai unka order decide krna , we do that using the lcs dp table.
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int i = 0;
        int j = 0;
        string ans = "";

        while (i < n && j < m) {
//when char matches then yeh toh pkka hai ki woh lcs mein hoga so superseq mein bhi hoga toh usko add kro
            if (s1[i] == s2[j]) {
                ans += s1[i];
                i++;
                j++;
            }
//ab when a char mismatches , ab humko nhi pta ki inme se konsa char lcs mein hai kyuki possibility is boh are in lcs or one of hem is in lcs or neither of them are.
//so dp[i+1] > dp[i][j+1] mtlb ki agr hum ith char ko na bhi le toh lcs ki len pe itna farak nhi pdta also jth char htane se lcs ki len choti ho rhi , so kya pta jth char in future lcs mein aa jaye but we are damn sure the path we chose , in this path ith char pkka nhiaayega lcs mein , now during printing of lcs we skip this char but in scs , we take this char kyuki read above , lcs ke alawa wale saare chars ko hum lete hai
            else if (dp[i+1][j] > dp[i][j+1]) {
                ans += s1[i];
                i++;
            } 
//same as above but hee we take jth char bcz dp[i][j] > dp[i].
            else {
                ans += s2[j];
                j++;
            }
        }

        while (i < n) {
            ans += s1[i];
            i++;
        }
        while (j < m) {
            ans += s2[j];
            j++;
        }
       
        return ans;
        
    }
};