//first approach obv which comes to mind is backtracking with vis array but that is wrong , recursion will fail everytime bcz of two condition:
// first say we are in a path A-C-B-D now at D we want to go to F but time at F > D so we will have to wait but we cant stay still in a cell , we have to waste time by going back and forth with nearby cells but in here we marked the prev cell as visited so we wont be able to visit it again , if we backtrack we say the path A-C-B-D-F is wrong which is incorrect bcz if we wasted time we can go reach F.
//if we dont use vis array at all , we would be stuck in infinite recursion as a recursion cal go to, next cell and prev cell so like A-B and B-A  again n again.
//hence think of smth else.

// DJIKSTRA algo , we treat time to reach nodes as their edge wt and store them with gid cells nto the PQ. we know if somehow we leave grid[0][0] then we can def reach dest cell bcz then we would have one cell to go back and forth to waste time. we just need to make couple of obvs to calc time to reach nodes carefully is all. 
class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    #define P pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));  //dist 2D vector but instead of dist it cnts time
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, {0, 0}}); // Start at top-left corner
        result[0][0] = 0;
        while (!pq.empty()) {
            // Get the current time, row, and column
            int time = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            
            // Reached destination
            if (row == m - 1 && col == n - 1)
                return result[m-1][n-1];
            
            // Mark the current cell as visited
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            // Explore the neighboring cells
            for (auto d: dir) {
                int r = row + d[0];
                int c = col + d[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                if (grid[r][c] <= time+1) {
                    pq.push({time+1, {r, c}});
                    result[r][c] = time+1;
                } else if ((grid[r][c]-time)%2==0) {
                    pq.push({grid[r][c]+1, {r, c}});
                    result[r][c] = grid[r][c]+1;
                } else {
                    pq.push({grid[r][c], {r, c}});
                    result[r][c] = grid[r][c];
                }
            }
        }
        return -1;
    }
};