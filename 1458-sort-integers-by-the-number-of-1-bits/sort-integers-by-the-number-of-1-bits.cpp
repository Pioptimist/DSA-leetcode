class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda=[](int &a, int &b){
            int cnt1a = __builtin_popcount(a);
            int cnt1b = __builtin_popcount(b);

            if(cnt1a == cnt1b){
                return a<b;
            }
            return cnt1a<cnt1b;
        };
        sort(begin(arr), end(arr), lambda);
        return arr;
    }
};