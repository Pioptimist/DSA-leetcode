class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        int i = 0;

        while (i < n) {
            char c = word[i];
            int count = 0;

            // count up to 9 of same char
            while (i < n && word[i] == c && count < 9) {
                count++;
                i++;
            }

            comp += to_string(count) + c;
        }

        return comp;
    }
};
