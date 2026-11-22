class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(heights[i]);
                ans[i] = 0;
            } else {
                while (!st.empty() && st.top() <= heights[i]) {
                    st.pop();
                    ans[i]++;
                }

                if (!st.empty()) ans[i]++;

                st.push(heights[i]);
            }
        }

        return ans;
    }
};