class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> ht(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                   q.push({i,j});
                   vis[i][j] = 1;
                }
            }
        }

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    ht[nr][nc] = ht[r][c] + 1;    //ht of land depending upon how far water is 
                    q.push({nr, nc});
                }
            }
        }

        return ht;
        
    }
};