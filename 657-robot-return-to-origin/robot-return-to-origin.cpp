// class Solution {
// public:
//     bool judgeCircle(string moves) {
//         map<char , pair<int,int>> dir;
//         dir['U'] = {0,1};
//         dir['D'] = {0,-1};
//         dir['L'] = {-1,0};
//         dir['R'] = {1,0};
//         pair<int,int> posn = {0,0};
//         for(char c : moves){
//             posn.first += dir[c].first;
//             posn.second += dir[c].second;
//         }

//         return posn == pair<int,int>{0,0};
//     }
// };
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;

        for(char c : moves){
            if(c == 'U') y++;
            else if(c == 'D') y--;
            else if(c == 'L') x--;
            else x++;
        }

        return x == 0 && y == 0;
    }
};