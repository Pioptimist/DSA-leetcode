class Solution {
public:
    bool isValid(const string &s){
        if(s[0] == '0') return false;

        int val = stoi(s);

        return val <= 255;
    }
    int n;
    vector<string> ans;
    void solve(string &s , int i , string curr , int parts){
        if(parts == 4 && i == n){

            curr.pop_back();
            ans.push_back(curr);

        }

        if(i + 1 <= n ){
            solve(s , i + 1 , curr + s.substr(i , 1) + '.' , parts + 1);
        }
        if(i + 2 <= n && isValid(s.substr(i , 2))){
            solve(s , i + 2 , curr + s.substr(i , 2) + '.', parts + 1);
        }
        if(i + 3 <= n && isValid(s.substr(i , 3))){
            solve(s , i + 3 , curr + s.substr(i , 3) + '.' , parts + 1);
        }
    }
    vector<string> restoreIpAddresses(string& s) {
        n = s.size();

        solve(s , 0 , "" , 0);

        return ans;

        
    }   
};
