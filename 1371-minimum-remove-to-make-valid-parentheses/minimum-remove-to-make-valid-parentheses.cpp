class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        stack<int> st; // stores indices of '('
        vector<bool> remove(n, false);  // characters to remove

        for(int i = 0; i < n; i++) {

            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {

                if(!st.empty()) {
                    st.pop(); // match
                }
                else {
                    remove[i] = true;   // unmatched ')'
                }
            }
        }

        // Remaining '(' are unmatched
        while(!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }

        string ans;

        for(int i = 0; i < n; i++) {
            if(!remove[i]) ans += s[i];
        }

        return ans;
    }
};