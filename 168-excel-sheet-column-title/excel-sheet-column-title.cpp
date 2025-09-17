class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; //turning to 0 based so if we have colno = 26 becomes 25, rem = 25 and char becomes = 25 + A = Z which we want
            int remainder = (columnNumber) % 26; 
            char c = 'A' + remainder;               
            result.push_back(c);
            columnNumber = (columnNumber) / 26; 
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
