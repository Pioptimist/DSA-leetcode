class Solution {
public:
//remove outermost parenthesis of every balanced parenthesis ie (()) is a balanced one , 
// (()()) is balanced
    string removeOuterParentheses(string s) {
       int n = s.size();
       string result = "";
       int cnt =0;
       for(int i =0;i<n;i++){
        
        if(s[i]==')') cnt--;

        if(cnt!=0) result.push_back(s[i]);

        if(s[i] == '(') cnt++;
       } 
       return result;
    }
};