class Solution {
public:
    bool compare(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) return false;
        int i = 0, j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++; j++;
            } else {
                i++; // skip one char in longer string
            }
        }
        return j == s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 1;
        vector<int> dp(n+1 , 1);
        sort(begin(words),end(words),[](string &s1 , string &s2){
            return s1.size() < s2.size();
        });
        for(int i = 0 ; i < n ; i++){
            for(int p  = 0 ; p  < i ; p++){
                if(compare(words[i],words[p]) && dp[i] < dp[p] + 1){
                    dp[i] = 1+ dp[p];
                    
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                
            }
        }
        
        return maxi;
        
    }
};