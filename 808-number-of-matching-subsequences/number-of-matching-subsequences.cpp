class Solution {
public:
    bool isSub(string word,map<char,vector<int>> &mpp,int n,int m){
        int k = word.size();
        int prev =-1;
        for(int i=0;i<k;i++){
            char ch = word[i];
            if(mpp.find(ch)==mpp.end()) return false;
            vector<int> ind = mpp[ch];
            auto it = upper_bound(begin(ind),end(ind),prev);
            if(it==ind.end()) return false;
            prev = *it;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mpp;
        int n = s.size();
        int m = words.size();
        for(int i =0;i<n;i++){
            mpp[s[i]].push_back(i);
        }
        int cnt = 0;
        unordered_map<string,bool> memo;  // using memoisation for duplicate words
        for(string& word : words) {
            if(memo.count(word)) {
                cnt += memo[word];
            }
            else {
                bool result = isSub(word, mpp,n,m);
                memo[word] = result;
                cnt += result;
            }
        }
        return cnt;
    }
};