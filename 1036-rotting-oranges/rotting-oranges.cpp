class Solution {
public:
//multisource bfs  , so put every src in q to start with
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If no fresh oranges
        if(fresh == 0) return 0;

        int minutes = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        
        while(!q.empty()) {
            int size = q.size();
            bool rottedThisMinute = false;

            for(int k = 0; k < size; k++) {
                auto [r, c] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];

                    if(nr >= 0 && nc >= 0 && nr < n && nc < m
                       && grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rottedThisMinute = true; // we only inc time if any orange is rotten
                    }
                }
            }

            if(rottedThisMinute) minutes++;
        }

        
        if(fresh > 0) return -1;

        return minutes;
    }
};