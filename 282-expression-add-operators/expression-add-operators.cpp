class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int index,
               string expr, long long value, long long prev) {

        if (index == num.size()) {
            if (value == target){
                cout << expr << " -> " << value << '\n';
                ans.push_back(expr);
            }
                
            return;
        }

        long long currNum = 0;

    
        for (int i = index; i < num.size(); i++) {

            // leading zeros ke liye jisse we dont select any number like 05 ,012 etc
            if (i > index && num[index] == '0')
                break;

            currNum = currNum * 10 + (num[i] - '0');

            string currStr = num.substr(index, i - index + 1);

            // First number: no operator before it
            if (index == 0) {
                solve(num, target,i + 1,currStr,currNum,currNum);
            }
            else {
                // +
                solve(num, target,i + 1,expr + "+" + currStr,value + currNum,currNum);

                // -
                solve(num, target,i + 1,expr + "-" + currStr,value - currNum,-currNum);

                // *
                solve(num, target, i + 1,expr + "*" + currStr,value - prev + prev * currNum,
                prev * currNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num, target, 0, "", 0, 0);

        return ans;
    }
};