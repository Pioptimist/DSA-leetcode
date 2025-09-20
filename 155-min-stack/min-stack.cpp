class MinStack {
public:
    stack<long long> st;
    long long mini = LLONG_MAX;   // use long long everywhere

    MinStack() {}
    
    void push(int val) {
        long long v = val;  // promote once
        if(st.empty()){
            mini = v;
            st.push(v);
        } 
        else{
            if(v > mini){
                st.push(v);
            }
            else{
                st.push(2*v - mini);
                mini = v;
            }
        }   
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini){
            mini = 2*mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1; // NULL for int is bad, return sentinel
        long long x = st.top();
        if(x >= mini) return (int)x;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};
