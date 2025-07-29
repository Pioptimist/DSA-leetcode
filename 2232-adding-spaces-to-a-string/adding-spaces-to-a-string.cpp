class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        int n = s.size();
        int m = spaces.size();
        string result = "";
        for(int i =0;i<n;i++){
            if(j<m && i == spaces[j]){
                result += " ";
                j++;
            }
            result += string(1,s[i]);
        }
        return result;

    }
};