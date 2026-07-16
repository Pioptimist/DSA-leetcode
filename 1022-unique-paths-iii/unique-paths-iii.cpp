class Solution {
public:
    int n;
    int m;
    int dfs(vector<vector<int>>& grid , int i , int j){
        if(grid[i][j] == 2){
            for(int i = 0 ; i<n ; i++){
               for(int j = 0 ; j<m ; j++){
                    if(grid[i][j] != -1 && grid[i][j] != 2){
                       return 0;
                    }
                }
            }
            return 1;
            
        }
        int temp = grid[i][j];
        grid[i][j] = -1; //mark as visited or obstacle same thing

        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int paths = 0;
        for(auto d : dir){
            int nr = i + d[0];
            int nc = j + d[1];
            if(nr >=0 && nr<n && nc>=0 && nc < m && grid[nr][nc] != -1 && grid[nr][nc] != 1){
                paths += dfs(grid , nr , nc);
            }
        }
        grid[i][j] = temp;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    ans+= dfs(grid , i , j);
                    return ans;
                }
            }
        }
        return ans;
        
    }
};