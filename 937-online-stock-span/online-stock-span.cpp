class StockSpanner {
public:
    stack<pair<int,int>> st; // we are storing prices with their span bcz when the next stock comes , we pop the prev lower prices , hence we need to know their span if we want to calc the current stock's span

    StockSpanner() {
        while(!st.empty()) st.pop();  // ensure it's clean
    }
    
    int next(int price) {
        int cnt = 1;
        while(!st.empty() && st.top().first <= price) {
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */