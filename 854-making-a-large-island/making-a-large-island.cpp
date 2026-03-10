
class Solution {
public:
    void dfs(int &size, int i , int j, vector<vector<int>> &grid,
         vector<vector<int>> &vis, int n, int id){
        vis[i][j] = id;
        size++;
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(int d =0;d<4;d++){
            int nr = i + dir[d][0];
            int nc = j + dir[d][1];

            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(size, nr , nc ,grid, vis , n , id);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n,0));
        unordered_map<int,int> mp;
        int id = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int size = 0;
                    id++;
                    dfs(size, i , j ,grid, vis, n, id);
                    mp[id] = size;
                }
            }
        }
        int ans = INT_MIN;
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> seen;
                    int curr = 1;
                    for(int d=0; d<4; d++){

                        int nr = i + dir[d][0];
                        int nc = j + dir[d][1];

                        if(nr>=0 && nr<n && nc>=0 && nc<n){
                            int islandId = vis[nr][nc];
                            if(islandId && seen.count(islandId)==0){
                                curr += mp[islandId];
                                seen.insert(islandId);
                            }
                        }
                    }
                    ans = max(ans,curr);
                }
            }
        }
        if(ans == INT_MIN) return n*n;
        return ans;
        
    }
};