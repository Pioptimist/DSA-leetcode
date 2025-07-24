class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m)  return false;
        vector<int> diff(26,0);

        for(int i =0;i<n;i++){
            diff[s[i]-'a']++;
        }

        for(int j =0;j<m;j++){
            diff[t[j]-'a']--;
        }
        
        for(int i =0;i<diff.size();i++){
            if(diff[i]!=0) return false;
        }
        return true;
    }
};