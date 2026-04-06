class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0; // assume dir according to the vector
        int dist = 0;
        int x = 0 , y= 0;
        set<pair<int,int>> st;
        for(auto &o : obstacles){
            st.insert({o[0],o[1]});
        }
        for(int i =0; i< n ; i++){
            if(commands[i] == -1){
               dir = (dir + 1) % 4; // right
            }
            else if(commands[i] == -2){
               dir = (dir + 3) % 4; // left
            }
            if(commands[i] > 0){
                int k = commands[i];
                for (int step = 0; step < k; step++) {
                    int nx = x + dirs[dir][0];
                    int ny = y + dirs[dir][1];
                    if (st.count({nx,ny})) break; 
                    x = nx;
                    y = ny;
                    dist = max(dist , x*x + y*y);
                    
                } 
            }
        }
        return dist;
        
    }
};

// class Solution {
// public:
//     bool check(int x , int y , vector<vector<int>>& o){
//         int m = o.size();
//         for(int i = 0 ; i< m; i++){
//             if(o[i] == vector<int>{x,y}) return true;
//         }

//         return false;
//     }
//     int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
//         int n = commands.size();
//         int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
//         int dir = 0; // assume dir according to the vector
//         int dist = 0;
//         int x = 0 , y= 0;
//         for(int i =0; i< n ; i++){
//             if(commands[i] == -1){
//                dir = (dir + 1) % 4; // right
//             }
//             else if(commands[i] == -2){
//                dir = (dir + 3) % 4; // left
//             }
//             if(commands[i] > 0){
//                 int k = commands[i];
//                 for (int step = 0; step < k; step++) {
//                     int nx = x + dirs[dir][0];
//                     int ny = y + dirs[dir][1];
//                     if (check(nx , ny , obstacles)) break; 
//                     x = nx;
//                     y = ny;
//                     dist = max(dist , x*x + y*y);
                    
//                 } 
//             }
//         }
//         return dist;
        
//     }
// };