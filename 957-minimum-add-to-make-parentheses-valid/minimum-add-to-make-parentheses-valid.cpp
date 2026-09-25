class Solution {
public:
//the thought of cnt++ for '(' and cnt -- for ')' will fail bcz look at this )( , returns 0 when the ans should be 2
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for(char c : s) {
            if(c == '(') {
                open++;
            } else {
                if(open > 0)
                    open--;
                else //unmatched )
                    ans++;
            }
        }

        return ans + open;
    }
};