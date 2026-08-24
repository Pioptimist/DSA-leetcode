#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions strictly mapped to match the problem description:
        // 1 = Right, 2 = Left, 3 = Down, 4 = Up
        // We use a dummy '0' at the start so indices 1-4 align perfectly.
        int dr[] = {0, 0, 0, 1, -1}; 
        int dc[] = {0, 1, -1, 0, 0};
        
        // Min-heap ordered by minimum cost: {cost, r, c}
        priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;
                       
        // Distance array initialized to infinity
        const int INF = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, INF));
        
        // Start at top-left
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();
            
            // If we reach the bottom-right corner, we are done
            if (r == m - 1 && c == n - 1) return cost;
            
            // Ignore stale entries in the priority queue
            if (cost > dist[r][c]) continue;
            
            // Explore all 4 possible directions
            for (int i = 1; i <= 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                // Check bounds
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Cost is 0 if we move in the grid's arrow direction, else 1
                    int edge_weight = (grid[r][c] == i) ? 0 : 1;
                    int nextCost = cost + edge_weight;
                    
                    // Relaxation step
                    if (nextCost < dist[nr][nc]) {
                        dist[nr][nc] = nextCost;
                        pq.push({nextCost, nr, nc});
                    }
                }
            }
        }
        
        return 0; // Should never be reached if grid is valid
    }
};