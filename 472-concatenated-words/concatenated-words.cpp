class Solution {
public:
    bool isConcatenate(vector<string>& words,string word,set<string> &st,unordered_map<string, bool> &mem){
        if(mem.count(word)) return mem[word];
        string pref;
        string suff;
        int m = word.size();
        for(int i =0;i<m;i++){
            pref= word.substr(0,i+1);     // 0 se i tk
            suff = word.substr(i+1);      //i+1 se end tk
            if((st.count(pref) && isConcatenate(words,suff,st,mem)) || st.count(pref) && st.count(suff)){     //check if suff can be broken further or not
                return mem[word] = true;
            }   
        }
        return mem[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        unordered_map<string, bool> mem;
        int n = words.size();
        set<string> st(words.begin(),words.end());
        for(int i =0;i<n;i++){
            if(isConcatenate(words,words[i],st,mem)){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};