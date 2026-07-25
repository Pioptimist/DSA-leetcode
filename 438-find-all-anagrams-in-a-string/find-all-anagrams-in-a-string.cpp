class Solution {
public:
//same as permutation of string , freq matters when said anagram, agr same freq then its an anagram
    bool allZeros(vector<int> &cnt){
        for(int i : cnt){
            if(i!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> res;
        if (n < m) return res;

        
        vector<int> cnt(26);
        
        for(int i =0;i<m;i++){
            char ch = p[i];
            cnt[ch - 'a']++;
        }
        int i=0,j= m-1;
        vector<int> window(26, 0);
        for(int i = 0 ; i < m ; i++) window[s[i] - 'a']++;

        int l = 0 , r = m - 1; //fixed window obv
        while(r < s.size()){
            if(window == cnt) res.push_back(l);
            //move left ahead
            window[s[l]-'a']--;
            l++;
            
            if(r == s.size() - 1) break;
            window[s[r+1]-'a']++; //move right ahead
            r++;
        }
        return res;
        
    }
};