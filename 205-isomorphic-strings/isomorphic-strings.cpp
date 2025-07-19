class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        set<char> mappedval;
        if(s.size()!=t.size()) return false;
        for(int i =0;i<s.size();i++){
            char sc =s[i], tc = t[i];
            if(mpp.find(sc)!=mpp.end()){
                if(mpp[sc]!=tc) return false;     // key is mapped but the value is different so not allowed
            }
            else{
                if(mappedval.count(tc)) return false;   //that key isnt mapped but the value is already here
                mpp[sc] = tc;
                mappedval.insert(tc);
            }
        }
        return true;
    }
   
};