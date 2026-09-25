class Solution {
public:
    int maxDepth(string s) {
        // if ( then cnt +1 if ) then cnt -1
        int cnt = 0;
        int maxcnt = 0;
        for(char ch : s){
          if(ch == '('){
            cnt++;
            maxcnt = max(maxcnt,cnt);
          }
          else if(ch == ')'){
            cnt--;
          }
        }
        return maxcnt;
    }
};