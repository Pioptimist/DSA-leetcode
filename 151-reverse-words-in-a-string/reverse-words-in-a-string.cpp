class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.size();
        string ans = "";
        for(int i =0;i<n;i++){
            string word = "";
            while(i<n && s[i]!=' '){
                word+= string(1,s[i]);
                i++;
            }
            if(!word.empty()){
                reverse(word.begin(),word.end());
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};