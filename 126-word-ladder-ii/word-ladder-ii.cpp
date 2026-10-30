class Solution {
    unordered_map<string, int> dist;
    vector<vector<string>> ans;
    string bWord;

//a simple concept of reverse dfs to avoid extra wastage of time bcz there can be words in the wordlist which may never lead to endword hence we go reverse
// If you start a forward DFS from beginWord looking for dist[next] == currStep + 1, the DFS will step into dozens of branches that satisfy the +1 math but actually lead to dead ends. For example, if beginWord is "hit" and endWord is "cog", the BFS might give "hot", "hat", and "hut" a distance of 2. If you do forward DFS, you might explore deep down the "hut" path, only to realize 10 steps later that it never connects to "cog". You have to backtrack all the way, wasting massive amounts of compute time.
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

                if (c == orig) continue;
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

        // Calculate minimum step distance to each reachable word , since undir graph a normal bfs will return shortest dist for each word like we saw in word ladder 1 , just store those distances in dist vector
        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int steps = dist[word];
            if (word == endWord) {
                found = true;
                break;
            }

            
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
                word[i] = orig; // reverse to original word
            }
        }
        //after this bfs we know this is undir unwt graph so if we reach endword , the dist arr will contain shortest dist to it , so we just go reverse from endword 

        // DFS Backtracking from endWord to beginWord
        if (dist.count(endWord)) {
            vector<string> path = {endWord};
            dfs(endWord, path);
        }

        return ans;
    }
};



