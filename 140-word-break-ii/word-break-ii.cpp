// class Solution {
// public:
//     vector<string> ans;
//     int n;
//     vector<
//     void f(int i ,string &s ,  vector<string>& wordDict, string sent){
//        if(i == n){
//         ans.push_back(sent);
//         return;
//        }
        
//        for(string word : wordDict){
//           if(s.substr(i , word.size()) == word){ //match , now check ahead
//             string next = sent; //this way we didnt touch sent for next iteration it remains clean.

//             if(next.empty()) next += word;

//             else next += " " + word;

//             f(i + word.size() , s , wordDict , next);
            
//           }
//        }
       

//     }
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         string sent;
//         n = s.size();
//         f(0 , s , wordDict , sent);

//         return ans;
        
//     }
// };
//this is an extension of word break 1 , but this is hard to memoise , and to think can we use dp take this eg abcdefgh and word dict of abc , abcd , ef , efg , gh , h , we will see overlapping subproblems

class Solution {
public:
    int n;
    vector<vector<string>> dp;
    vector<int> vis;

    vector<string> f(int i, string &s, vector<string> &wordDict) {

        if (i == n)
            return {""};          

        if (vis[i])
            return dp[i];

        vis[i] = 1;

        vector<string> ans;

        for (string &word : wordDict) {

            if (i + word.size() <= n &&  //if the word matches so take it
                s.compare(i, word.size(), word) == 0) {

                vector<string> suffixes = f(i + word.size(), s, wordDict);  //recursion call krdo jisse aage ke combn se jitne bhi possible sentences bn skte woh humare pe aajaye for eg suppose we send "efgh" and wordD has efg , h , ef , gh so two possible scenario "ef gh" and "efg h" , so traverse over both and append word with them

                for (string &suffix : suffixes) {

                    if (suffix == "")  //empty string aa gya toh simply word ko add kro aur kuch nhi 
                        ans.push_back(word);
                    else
                        ans.push_back(word + " " + suffix);  //agar suffix hai , toh word ko correctly append
                }
            }
        }

        return dp[i] = ans;  //memoise now dp[i] holds the vector string 
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        n = s.size();
        dp.resize(n);
        vis.assign(n, 0);

        return f(0, s, wordDict);
    }
};

// here f means siply return the ans , all possible sentences turn krdo for s[i..]
