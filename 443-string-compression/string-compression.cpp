class Solution {
public:
    int compress(vector<char>& chars) {
        int n =chars.size();
        int check = 0;
        int i = 0;
        while(i<n){
            char curr_char = chars[i];
            int cnt = 0;
            while(i<n && chars[i]==curr_char){
                cnt++;
                i++;
            }
            chars[check]= curr_char;
            check++;
            
            if(cnt>1){
              string cnt_str = to_string(cnt);
              for(char ch : cnt_str){
                chars[check] = ch;
                check++;
              }
            }
        }
        return check;
    }
};