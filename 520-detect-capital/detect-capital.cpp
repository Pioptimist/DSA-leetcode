class Solution {
public:
    bool detectCapitalUse(string word) {
        int n =word.size();
        int cntupp = 0;
        for(char ch :word){
            if(isupper(ch)){
                cntupp++;
            }
        }
        if(cntupp==0 || cntupp==n || (cntupp==1 && isupper(word[0]))){
            return true;
        }
        return false;
    }
};