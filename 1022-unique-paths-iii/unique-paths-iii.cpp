// class Solution {
// public:
//     int n;
//     int m;
// //this is a question of backtracking where we make sure to visit every cell we can but not more than once and if so we get to destn , return 1 as valid path otherwise prune and backtrack and undo the cell as visited
//     int dfs(vector<vector<int>>& grid , int i , int j){
//         if(grid[i][j] == 2){
//             for(int i = 0 ; i<n ; i++){
//                for(int j = 0 ; j<m ; j++){
//                     if(grid[i][j] != -1 && grid[i][j] != 2){
//                        return 0;
//                     }
//                 }
//             }
//             return 1;
            
//         }
//         int temp = grid[i][j];
//         grid[i][j] = -1; //mark as visited or obstacle same thing

//         int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
//         int paths = 0;
//         for(auto d : dir){
//             int nr = i + d[0];
//             int nc = j + d[1];
//             if(nr >=0 && nr<n && nc>=0 && nc < m && grid[nr][nc] != -1 && grid[nr][nc] != 1){
//                 paths += dfs(grid , nr , nc);
//             }
//         }
//         grid[i][j] = temp;
//         return paths;
//     }
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         n = grid.size();
//         m = grid[0].size();
//         int ans = 0;
//         for(int i = 0 ; i<n ; i++){
//             for(int j = 0 ; j<m ; j++){
//                 if(grid[i][j] == 1){
//                     ans+= dfs(grid , i , j);
//                     return ans;
//                 }
//             }
//         }
//         return ans;
        
//     }
// };



//now this is actually a question of dp with bitmask as: first the number of paths depend on i , j and cells we have visited , second we reaach the same state say same i ,j and visited cell as before again and again => dp. now we can use vis array to know what cells are isited but then how will we memoise or hash it , one way is For example, you could do something like =>
// map<pair<pair<int,int>, vector<vector<bool>>>, int> dp; or unordered_map<string, int> dp; where you convert the visited matrix into a string like 001101011010... Then your key is
// (i, j, "001101011010...")This would work but on every recursion call we will have to turn the vis aray into string and then compare and hash, extra overhead and hence this give rise to => BITMASK
// so the idea of bitmask is we treat every cell vis or not vis as binary digit and then convert that into a bitmask of decimal number . assign every cell an id : Cell (0,0) → bit 0
// Cell (0,1) → bit 1
// Cell (1,0) → bit 2
// Cell (1,1) → bit 3
// suppose we visited 0,0 (0,1) and (1,1) then bitmask is 1     0     1     1 or mask = 11
// imp four formulas using bitmask :
// // Set bit i
// mask |= (1 << i);
// // Remove bit i
// mask &= ~(1 << i);
// // Check bit i
// (mask & (1 << i))
// // Toggle bit i
// mask ^= (1 << i);

class Solution {
public:

    int n,m;
    int targetMask; //this should have all cells set except the obstacle one

    int dfs(vector<vector<int>>& grid,
            int i,
            int j,
            int mask,
            vector<vector<vector<int>>>& dp){

        if(grid[i][j]==2) return mask==targetMask;  //either 0 or 1

        if(dp[i][j][mask]!=-1) return dp[i][j][mask];

        int ans=0;
        int dir[4][2]={ {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        for(auto &d:dir){
            int nr= i + d[0];
            int nc= j + d[1];

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;

            if(grid[nr][nc]==-1) continue;

            int id=nr*m+nc;
            if(mask&(1<<id)) continue;  //mtlb yeh wale cell ka bit set hai e visited , skip

            ans+=dfs(grid,nr, nc, mask|(1<<id), dp); //mark visited
        }

        return dp[i][j][mask]=ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        targetMask=0;
        int si,sj;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]!=-1){
                    int id=i*m+j; //0 ,1 ,2... like this hr cell ko ek bit boldo
                    targetMask |= (1<<id); //set that bit/cell as 1
                }

                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
            }
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1<<(n*m),-1)));
        int startMask=(1<<(si*m+sj)); //start index ko vis mark krdo

        return dfs(grid,si,sj,startMask,dp);
    }
};