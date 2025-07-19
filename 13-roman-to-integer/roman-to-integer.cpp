class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = {{'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size();
        int result =0;
        for(int i =0;i<n;i++){
            if(i+1<n && mpp[s[i]]<mpp[s[i+1]]){
               result -= mpp[s[i]];
            }
            else{
                result += mpp[s[i]];
            }
        }
        return result;
    }
};