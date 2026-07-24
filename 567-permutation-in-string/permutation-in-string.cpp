class Solution {
public:
//one of permutuation mtlb order doest matter for eg for abc , can cba , acb , bca , cab etc so only freq of chars matter and both has to be of same length , think sliding window
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        int n = s1.size();
        vector<int> need(26, 0);
        for(char c : s1) need[c - 'a']++;
        
        vector<int> window(26, 0);
        for(int i = 0 ; i < n ; i++) window[s2[i] - 'a']++;

        int l = 0 , r = n - 1; //fixed window obv
        while(r < s2.size()){
            if(window == need) return true;
            //move left ahead
            window[s2[l]-'a']--;
            l++;
            
            if(r == s2.size() - 1) break;
            window[s2[r+1]-'a']++; //move right ahead
            r++;
        }
        return false;
    }
};