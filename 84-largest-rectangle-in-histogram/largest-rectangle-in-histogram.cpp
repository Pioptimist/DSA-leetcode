class Solution {
public:
//the  obv solution is using pse and nse but to optimise tc further we try to do this in a single pass , so we go from left to right and calc pse but during that when we keep popping elements, we can say the curr element can be nse for the popped element and the top element which remain after popping one element is the pse for the popped ele
    int largestRectangleArea(vector<int>& heights) {
        int maxar = 0;
        stack<int> st;
        int n = heights.size();
        //here we find nse and pse when we pop the element
        for(int i =0;i<n;i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                int elem = heights[st.top()];
                st.pop();
                int nse = i; //curr element is nse for this popped element
                int pse = st.empty() ? -1 : st.top(); //the element which is top has def be pse of this popped element since its a monotonic stack

                maxar = max(maxar, (elem*(nse-pse-1))); //calc the area of rect formed by the popped ele.
            }
            st.push(i);
        }
        //for leftover elements and we know that these elements left cant have nse bcz if they did we would have it above
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