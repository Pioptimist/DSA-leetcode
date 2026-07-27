class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 0));
        for(int i =0;i<n ; i++){
            for(int j =0 ; j< m ; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1} };
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(int i =0;i < 4 ;i++){
                int newr = r + dir[i][0];
                int newc = c + dir[i][1];
                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc] == 0){
                    vis[newr][newc] = 1;
                    dist[newr][newc] = steps+1;
                    q.push({{newr,newc} , steps + 1});

                }
            }
        }

        return dist;
        
    }
};