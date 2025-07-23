class Solution {
public:
    bool isvowel(char ch){
        char t = tolower(ch);
        return (t=='a' || t=='e' || t=='i' || t=='o' || t=='u');
    }
    string sortVowels(string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(isvowel(s[i])){
                mpp[s[i]]++;
            }
        }

        string vowels = "AEIOUaeiou";
        int j =0;

        for(int i =0;i<n;i++){
            if(isvowel(s[i])){
                while(mpp[vowels[j]]==0){       //this points to the first char in vowels which is in s
                    j++;
                }
                s[i]= vowels[j];
                mpp[vowels[j]]--;

            }
        }
        return s;
    }
};