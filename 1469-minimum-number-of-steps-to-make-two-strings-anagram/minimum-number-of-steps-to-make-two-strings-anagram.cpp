class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return -1;
        int result=0;

        vector<int> diff(26);
        for(int i =0;i<n;i++){
            diff[s[i]-'a']++;    
        }
        for(int j =0;j<m;j++){
            diff[t[j]-'a']--;       //this will give us diff of freq of char in s and t and wherever diff is positive ie that particular char is more in s and for s and t to be anagram t should have same freq of that char as of s
        }  
        for(int i =0;i<26;i++){
            if(diff[i]>0){
                result += diff[i];

            }
        }
        return result;
    }
};