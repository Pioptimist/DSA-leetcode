class Solution {
public:
    bool isValid(string &word, unordered_set<string> &st) {
        return st.find(word) != st.end();
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0;
        int n = beginWord.size();
    
        queue<pair<string , int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word, step] = q.front();
            q.pop();

            if(word == endWord){
                return step;
            }
            string temp = word;
            for(int i = 0 ; i<n; i++){
                for(char c = 'a';c <='z'; c++){
                    word[i] = c;
                    if(isValid(word,st)){
                        q.push({word , step + 1});
                        st.erase(word);
                    }
                }
                word = temp;
            }
        }

        return 0;   
    }
};