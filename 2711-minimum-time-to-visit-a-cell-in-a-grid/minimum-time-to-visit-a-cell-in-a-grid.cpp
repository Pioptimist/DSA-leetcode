//first approach obv which comes to mind is backtracking with vis array but that is wrong , recursion will fail everytime bcz of two condition:
// first say we are in a path A-C-B-D now at D we want to go to F but time at F > D so we will have to wait but we cant stay still in a cell , we have to waste time by going back and forth with nearby cells but in here we marked the prev cell as visited so we wont be able to visit it again , if we backtrack we say the path A-C-B-D-F is wrong which is incorrect bcz if we wasted time we can go reach F.
//if we dont use vis array at all , we would be stuck in infinite recursion as a recursion cal go to, next cell and prev cell so like A-B and B-A  again n again.
//hence think of smth else.

// DJIKSTRA algo , we treat time to reach nodes as their edge wt and store them with grid cells into the PQ. we know if somehow we leave grid[0][0] then we can def reach dest cell bcz then we would have one cell to go back and forth to waste time. we just need to make couple of obvservation to calc time to reach nodes carefully. keep the algo exactly same , we try every nodes 
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
        
        pq.push({0, {0, 0}}); // {t , {i,j}}
        result[0][0] = 0;
        while (!pq.empty()) {
            int time = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            
        
            if (row == m - 1 && col == n - 1){
                return result[m-1][n-1];
            }
                
            if (visited[row][col]) continue; // Mark the current cell as visited

            visited[row][col] = true; //we mark visited only when we get this node from pq ie it means this is minimum possible time to reach this node , no lesser time can be found , thats why visited is imp here bcz it essentially tells us , if this is the min time to reach this node, why would we reach here again to only inc time
            
//remember even tho we mark the prev as visited, in our head for time wasting we would need to go back and forth in one prev cell.
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
                    result[r][c] = grid[r][c]+1;  //if their diff is even ,then we can go back n forth to waste time and time will get rime + 1 when we reach that cell
                } else {
                    pq.push({grid[r][c], {r, c}});
                    result[r][c] = grid[r][c];  //if diff is odd , then after wasting time , we will exactly reach at time = grid[r][c] at (r,c).
                }
            }
        }
        return -1;
    }
};
//we dont need result arr , we can do this without it too.