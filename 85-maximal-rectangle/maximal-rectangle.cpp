class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxar = 0;
        stack<int> st;
        int n = heights.size();
        for(int i =0;i<n;i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                int elem = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxar = max(maxar, (elem*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse  = n;
            int elem = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxar = max(maxar, (elem*(nse-pse-1)));
        }
        return maxar;

        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};