class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int currMax = top.first;
            int r = top.second.first;
            int c = top.second.second;

            if(r == n-1 && c == n-1)
                return currMax;

            for(int k=0;k<4;k++) {

                int nr = r + dir[k][0];
                int nc = c + dir[k][1];

                if(nr>=0 && nr<n && nc>=0 && nc<n) {

                    int extra = 0;

                    if(grid[nr][nc] > currMax)
                        extra = grid[nr][nc] - currMax;

                    int newCost = currMax + extra;

                    if(newCost < dist[nr][nc]) {

                        dist[nr][nc] = newCost;
                        pq.push({newCost, {nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};