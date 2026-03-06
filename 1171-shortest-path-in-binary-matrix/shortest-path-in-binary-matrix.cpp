class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<vector<int>> q;
        
        if(grid[0][0]== 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> vis(n, vector<int>(n,0));
        q.push({0,0,1});
        vis[0][0] = 1;
       
        while(!q.empty()){
            vector<int> vec = q.front();
            q.pop();
            
            int r = vec[0];
            int c = vec[1];
            int step = vec[2];
            if(r == n-1 && c==n-1) return step;

            int dir[8][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}, {1,-1}, {1,1}, {-1,-1}, {-1,1}};
            for(int d =0; d<8; d++){
                int newr = r + dir[d][0];
                int newc = c + dir[d][1];

                if(newr>=0 && newr<n && newc>=0 && newc<n && !vis[newr][newc] && grid[newr][newc]== 0){
                    vis[newr][newc] = 1;
                    q.push({newr,newc,step+1});
                }
            }
        }

        return -1;
        
    }
};