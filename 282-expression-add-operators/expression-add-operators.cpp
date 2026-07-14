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

        solve(num, target, 0, "", 0, 0); //num ,target , ind , expr , total value , prev operand

        return ans;
    }
};

//ques of simple recursion and backtracking where we keep selecting digits and apply opretors between them , but one thing which fucks this up is , the mult operator which makes us follow operator precedance for eg say we have num = "123", target = 6 , we call recursion we selected 1 and then call recursion for [2,3] and suppose we put + after so 1 + [2,3] , then we chose 2 so 1 + 2 and now we choose mult for eg 1 + 2 * 3 , if we didnt have prev then there was no way to distinguish whether we should do 3 * 3 which is 9 or do 1 + 6=7 which follows operator precedance

//hence in prev var we send the prev operand so like for 1 + 2 , prev is 2 same for - like 1 - 2 , prev is 2 but for mult now suppose we got (1 + 2) ie value is 3 and we called next recursion with mult with prev being 2 obv now we know we need 1 + 2*3 not 3*3 so we do val - prev + prev*currnum => 3-2 + 2*3 = 7. so prev in this call becomes 2*3 or prev*currnum.

//next up is leading zeros , take this number for eg 105 , we start the call from ind = 0 ie on 1 now we call the next call ie 1 +/*/- [05] , remember this , we can take 0 as a number itself but anything starting with 0 is not a valid number like 05 , 012 , 09 are not valid bcz 14 * 05 or 345-0123 doesnt make sense.
//continuing the eg of 105 now we are the next call ie we take 0 as solo , the cond if (i > index && num[index] == '0') doesnt satisfies as index is 1 and i =1 too but in next trav ie 05 the cond gets true and we break out of the loop , we dont continue bcz as soon as ek bhi leading zero aa gya , usse bnne wale hr ek number invalid honge be that be 05 , 07 ,012,0123,02534 anything.

//also one last thing the idea of conveting the string expression adn calc the val at base case to match with target might come to mind but that will fail tc so we evaluate the expression on the go .
                