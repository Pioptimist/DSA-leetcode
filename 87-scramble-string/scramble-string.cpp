class Solution {
public:
    map<string , bool> mp;

    bool f(string s1 , string s2){
        if(s1 == s2) return true;

        if(s1.size() != s2.size()) return false;

        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end()) return mp[key];

        // pruning (important)
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a != b) return mp[key] = false;

        int n = s1.size();

        for(int i = 1; i < n; i++){

            // no swap
            bool notSwap =
                f(s1.substr(0, i), s2.substr(0, i)) &&
                f(s1.substr(i), s2.substr(i));

            // swap
            bool swap =
                f(s1.substr(0, i), s2.substr(n-i)) &&
                f(s1.substr(i), s2.substr(0, n-i));

            if(notSwap || swap){
                return mp[key] = true;
            }
        }

        return mp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return f(s1, s2);
    }
};