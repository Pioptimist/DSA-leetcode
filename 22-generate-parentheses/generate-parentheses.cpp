class Solution {
public:

    vector<string> ans;

    void f(int n, int open, string s) {
        if(n == 0) {
            if(open == 0) {
                ans.push_back(s);
            }

            return;
        }

        f(n - 1, open + 1, s + "(");

        if(open > 0) {
            f(n - 1, open - 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {

        f(2 * n, 0, "");   // 3 parenthesis means 6 brackets 
        return ans;
    }
};