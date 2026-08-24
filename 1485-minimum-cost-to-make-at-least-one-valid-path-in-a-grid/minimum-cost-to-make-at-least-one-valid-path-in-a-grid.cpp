class Solution {
public:
    // look at the ques up close , its a ques of graph where wt of edges can be either 0 or 1 depending on the dir we are moving , so the ques is the path with min cost => djikstra
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // if cell is 1 , we go right  , if cell is 2 we got left and so on , hence the dir vector
        int dr[] = {0, 0, 0, 1, -1}; 
        int dc[] = {0, 1, -1, 0, 0};
        
      
        priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;
                       
      
        const int INF = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, INF));
        
       
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();
            
           
            if (r == m - 1 && c == n - 1) return cost;
            
            if (cost > dist[r][c]) continue;
            for (int i = 1; i <= 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
            
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Cost is 0 if we move in the grid's arrow direction, else 1
                    int edge_weight = (grid[r][c] == i) ? 0 : 1; //edge wt depends on the dir we are going
                    int nextCost = cost + edge_weight;
                    
                    if (nextCost < dist[nr][nc]) {
                        dist[nr][nc] = nextCost;
                        pq.push({nextCost, nr, nc});
                    }
                }
            }
        }
        
        return 0; // if graph aint valid
    }
};