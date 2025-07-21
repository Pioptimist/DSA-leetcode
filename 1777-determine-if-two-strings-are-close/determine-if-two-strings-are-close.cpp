class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(m!=n) return false;
        vector<int> freq1(26);
        vector<int> freq2(26);
        for(int i =0;i<n;i++){
            int ind1 = word1[i]-'a';
            int ind2 = word2[i]-'a';
            freq1[ind1]++;
            freq2[ind2]++;
        } 
        for(int i = 0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0) continue;
            if(freq1[i]==0 && freq2[i]==0) continue;
            return false;
        }
        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));

        return freq1==freq2; 
    }
};