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
};