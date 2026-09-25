class Solution {
public:
//not dp , just a simple stack problem to evaluate the exp , the dp one is in striver's vid.
    bool parseBoolExpr(string expression) {

        stack<char> st;

        for(char ch : expression){ // dry run on this !(&(f,t))
            // Ignore commas and opening brackets
            if(ch == ',' || ch == '(')
                continue;

            // Evaluate one complete expression
            if(ch == ')'){

                int t = 0;
                int f = 0;

                // Collect operands
                while(st.top() == 't' || st.top() == 'f'){
                    if(st.top() == 't') t++;
                    else f++;
                    st.pop();
                }

                char op = st.top();
                st.pop();

                if(op == '&'){
                    st.push(f == 0 ? 't' : 'f');
                }
                else if(op == '|'){
                    st.push(t > 0 ? 't' : 'f');
                }
                else{ // '!'
                    st.push(f == 1 ? 't' : 'f');
                }
            }
            else{
                st.push(ch);
            }
        }

        return st.top() == 't';
    }
};