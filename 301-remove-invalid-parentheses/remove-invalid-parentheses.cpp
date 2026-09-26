// class Solution {
// public:
//     unordered_set<string> resultSet;
//     //using a set bcz if we have ((( or ))) smth like this , then we will get duplicate ans , try dry running on first test case , so set prevents that
//     void f(int i , string s , int ropen , int rclose , int bal  , string str){
//         if(i == s.size()){
//             if(ropen == 0 && rclose == 0){
//                if(bal == 0){
//                    resultSet.insert(str);
//                    return;
//                 }

//                 return;  // invalid state
//             }
//             return;
//         }

        
//         if(s[i] == '('){
//             f(i+1 , s , ropen , rclose , bal + 1  , str + s[i]); // take

//             if(ropen > 0){
//                 f(i+1 , s , ropen - 1 , rclose , bal , str); // not take
//             }

//         }
//         else if(s[i] == ')'){
//             if (bal > 0) { // if bal is less than zero , never ever take another ) bcz that whole path should be pruned for eg )()
//                 f(i+1, s, ropen, rclose, bal - 1, str + s[i]); // take
//             }

//             if(rclose > 0){
//                 f(i+1 , s , ropen , rclose - 1 , bal , str); // not take
//             }
//         }
//         else{
//             //an alphabet encountered , take it
//             f(i+1 ,s , ropen , rclose , bal , str + s[i]);
//         }
//     }
//     vector<string> removeInvalidParentheses(string s) {
        
//         int ropen = 0;
//         int rclose = 0;

//        for (char c : s) {
//             if (c == '(') {
//                ropen++;
//             } else if (c == ')') {
//                 if (ropen > 0)  ropen--;
//                 else rclose++;
//             }
//         }
//         // now we know number of invalid parenthesis ,

        
//         f(0 , s , ropen , rclose , 0 , "");

//         return vector<string>(resultSet.begin(), resultSet.end());  
//     }
// };

// the above is dfs method  , the brute or naive method and will mle unless optimisations are done 
// but ths ques can be done if we think BFS by thinking each level as all possible variation of string if we remove one parethesis , so lvl 1 , all variation when we removed one parenth , then lvl2 when we remove another parenth , so on and on , this guarantess that the very first time we find a valid string , than we can surely say this is the minimal removal req as bfs on unord gives min path or shortest path

class Solution {
    bool isValid(const string& str) {
        int bal = 0;
        for (char c : str) {
            if (c == '(') bal++;
            else if (c == ')') {
                bal--;
                if (bal < 0) return false;
            }
        }
        return bal == 0;
    }

public:
    vector<vector<string>> removeInvalidParentheses_bfs(string s) {
        // Dummy wrapper if needed
        return {};
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                ans.push_back(curr);
                found = true; 
            }

            // Once we found any valid string at this removal depth,
            // we do NOT generate deeper states (depth + 1).
            if (found) continue;

            // Generate next-level neighbors (delete 1 bracket)
            int len = curr.size();
            for (int i = 0; i < len; i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                // Optimization: Skip consecutive identical characters to avoid duplicate string creations
                if (i > 0 && curr[i] == curr[i - 1]) continue;

                string nxt = curr.substr(0, i) + curr.substr(i + 1);
                if (!visited.count(nxt)) {
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
        }

        return ans;
    }
};

