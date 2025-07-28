class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> hash(26);
        int n = s.size();

        for(int i =0;i<n;i++){
            int  ind = s[i] - 'a';
            hash[ind]++;
        }
        string result ="";
        int m = order.size();
        int j=0;
        while(j<m){
            if(hash[order[j]-'a']!=0){
                result += string(hash[order[j]-'a'],order[j]);
                hash[order[j]-'a'] = 0;
            }
            j++;
        }
        for(int i =0;i<26;i++){
            if(hash[i]!=0){
                char ch = 'a' + i;
                result = result + string(hash[i],ch);
            }
        }
        return result;
    }
};