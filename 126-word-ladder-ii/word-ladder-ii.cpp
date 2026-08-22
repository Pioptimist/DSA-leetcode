class Solution {
    unordered_map<string, int> dist;
    vector<vector<string>> ans;
    string bWord;

    void dfs(string word, vector<string>& path) {
        if (word == bWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            ans.push_back(validPath);
            return;
        }

        int currStep = dist[word];
        int n = word.size();

        for (int i = 0; i < n; i++) {
            char orig = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                // Walk strictly uphill: only step to parents whose distance is exactly currStep - 1
                if (dist.count(word) && dist[word] == currStep - 1) {
                    path.push_back(word);
                    dfs(word, path);
                    path.pop_back();
                }
            }
            word[i] = orig;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        bWord = beginWord;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        dict.erase(beginWord);

        int n = beginWord.size();
        bool found = false;

        // BFS: Calculate minimum step distance to each reachable word
        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int steps = dist[word];
            if (word == endWord) {
                found = true;
                break;
            }

            string temp = word;
            for (int i = 0; i < n; i++) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == orig) continue;
                    word[i] = c;

                    if (dict.count(word)) {
                        q.push(word);
                        dist[word] = steps + 1;
                        dict.erase(word); // Safe to erase once recorded in dist
                    }
                }
                word[i] = orig;
            }
        }

        // DFS Backtracking from endWord to beginWord
        if (dist.count(endWord)) {
            vector<string> path = {endWord};
            dfs(endWord, path);
        }

        return ans;
    }
};