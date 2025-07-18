class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        
        string say = countAndSay(n-1);
        
        string result = "";
        
        // Just count and store in result and return
        int i =0;
        while(i<say.length()) {
            
            int count = 0;
            char ch = say[i];
            
            while(i < say.length() && say[i] ==ch) {
                count++;
                i++;
            }
            
            result += to_string(count) + ch;
            
        }
        
        return result;
        
    }
};