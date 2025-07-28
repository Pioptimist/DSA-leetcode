class Solution {
public:
    void Lps(vector<int> &lps,string word,int n){
        lps[0] = 0;
        int i = 1;
        int len = 0;

        while(i<n){
            if(word[i] == word[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> lps(n);

        Lps(lps,word,n);
        int len_suff = lps[n-1];
        while(len_suff>0 && (n-len_suff)%k!=0){
            len_suff = lps[len_suff-1];
        }
        int remaining = n - len_suff;
        return (remaining + k - 1) / k;   //always return ceil value
    }
};