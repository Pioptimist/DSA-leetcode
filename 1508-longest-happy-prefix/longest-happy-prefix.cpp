class Solution {
public:
//just return lps of n-1
    vector<int> buildLPS(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n; ) { //we inc i when we want to , no auto increment
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps = buildLPS(s);

        int len = lps[n - 1];
        return s.substr(0, len);
    }
};


// string longestPrefix(string s) {

//         int n = s.size();
//         string ans = "";

//         for(int len = 1; len < n; len++) {

//             string prefix = "";
//             for(int i = 0; i < len; i++) {
//                 prefix += s[i];
//             }

//             bool match = true;

//             for(int i = 0; i < len; i++) {
//                 if(prefix[i] != s[n - len + i]) {  //ababab for dry run
//                     match = false;
//                     break;
//                 }
//             }

//             if(match) ans = prefix;
//         }

//         return ans;
//     }  O(n2) gives tle