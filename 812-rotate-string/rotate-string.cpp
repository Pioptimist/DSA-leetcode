class Solution {
public:
    // Step 1: Build the LPS (Longest Prefix Suffix) array
    vector<int> buildLPS(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n; ) {
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

    // Step 2: Use KMP to search goal in s + s
    bool kmpSearch(string& text, string& pattern) {
        vector<int> lps = buildLPS(pattern);
        int i = 0, j = 0;
        int n = text.size(), m = pattern.size();
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++; j++;
            } 
            if (j == m) return true; // pattern found
            else if (i < n && text[i] != pattern[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }

    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubled = s + s;
        return kmpSearch(doubled, goal);
    }
};
