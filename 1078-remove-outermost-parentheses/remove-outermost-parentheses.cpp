class Solution {
public:
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