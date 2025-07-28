class Solution {
public:
    bool check(int ind, int len,string word,string temp,int k){
        if(word.substr(0,len) == temp.substr(ind)){
            return true;
        }
        else{
            return false;
        }
        return false;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int i = k;
        string temp = word;
        int cnt = 1;
        while(i<n){
            if(check(i,n-i,word,temp,k)){
                return cnt;
            }
            else{
                i += k;
                cnt++;
                
            }
        }
        return cnt;  //if they never match so just return the cnt
    }
};