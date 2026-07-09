class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>>,
        greater<pair<int , pair<int,int>>>> pq;
        
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> diff(r , vector<int>(c , INT_MAX));
        diff[0][0] = 0;

        pq.push({0 , {0,0}});
        int dir[4][2] = {{0,1} , {1,0}, {-1,0} , {0,-1}};
        while(!pq.empty()){
            auto [d, cell] = pq.top();
            pq.pop();

            int i = cell.first;
            int j = cell.second;

            if (d > diff[i][j]) continue;
           
            for(auto dirr : dir){
                int newr = i + dirr[0];
                int newc = j + dirr[1];

                if(newr >=0 && newr < r && newc>=0 && newc < c){
                    int difference = abs(heights[i][j] - heights[newr][newc]);
                    int to_upd = max(difference , d);
                    if(to_upd < diff[newr][newc]){
                        diff[newr][newc] = to_upd;
                        pq.push({to_upd, {newr, newc}});
                    }
                }


            }

        }
        return diff[r-1][c-1];
        
    }
};