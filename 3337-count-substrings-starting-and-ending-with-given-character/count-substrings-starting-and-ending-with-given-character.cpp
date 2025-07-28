class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cntofc = 0;
        long long numofsubstr = 0;
        for(char ch : s){
            if(ch == c){
                numofsubstr += (1+cntofc);
                cntofc++;
            }
        }
        return numofsubstr;
    }
};