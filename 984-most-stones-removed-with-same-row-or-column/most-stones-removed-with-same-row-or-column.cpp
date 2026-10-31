// class DSU {
// public:
//     vector<int> parent, rank;

//     DSU(int n){
//         parent.resize(n);
//         rank.resize(n,0);

//         for(int i=0;i<n;i++)  parent[i] = i;
//     }

//     int find(int x){
//         if(parent[x] == x) return x;
//         return parent[x] = find(parent[x]);
//     }

//     void unite(int x,int y){
//         int pu = find(x);
//         int pv = find(y);

//         if(pu == pv) return;

//         if(rank[pu] < rank[pv]){
//             parent[pu] = pv;
//         }
//         else if(rank[pv] < rank[pu]){
//             parent[pv] = pu;
//         }
//         else{
//             parent[pv] = pu;
//             rank[pu]++;
//         }
//     }
// };

// class Solution {
// public:
// //treat rows and cols as nodes 
//     int removeStones(vector<vector<int>>& stones) {
//         int maxr = 0;
//         int maxc = 0;

//         for(auto &it: stones){
//             maxr = max(maxr, it[0]); //find the number of rows here and cols
//             maxc = max(maxc, it[1]);
//         }

//         DSU ds(maxr + maxc + 2); //total number of nodes is r + c + 2

//         unordered_map<int,int> mp;

//         for(auto &it : stones){
//             int noder = it[0];
//             int nodec = it[1] + maxr + 1;  //to represent col as node , for 0th col we do 0 + r + 1. for eg there are 4 rows , r = 3 , so node = 0,1,2,3 for row to represent 0th col , we do 0 + 3 + 1 ie 4,5,6 ...

//             ds.unite(noder, nodec);
            
//             mp[noder] = 1;   //keep overwriting bcz we want all rows and cols given in ques , so we can calc ult parent later
//             mp[nodec] = 1;
//         }

//         int cnt = 0; 

//         for(auto &it : mp){
//             if(ds.find(it.first) == it.first) cnt++;  // cnt ult parent
//         }

//         return stones.size() - cnt;
//     }
// };
//numbers of removal is total number of stones - number of connected components


// another approach to solev this can be a simple dfs to find size of conn component , we just ned to hash stones which share same row and col as the one we are on and then find the compoent size .
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, false);
        int components = 0;

        // Count connected components
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                components++;
                dfs(i, stones, vis);
            }
        }

        // The answer is always total stones minus the number of separate components
        return n - components;
    }

private:
    void dfs(int src, vector<vector<int>>& stones, vector<bool>& vis) {
        vis[src] = true;
        
        for (int i = 0; i < stones.size(); ++i) {
            if (!vis[i]) {
                // If they share either the same row or same column, they are connected
                if (stones[src][0] == stones[i][0] || stones[src][1] == stones[i][1]) {
                    dfs(i, stones, vis);
                }
            }
        }
    }
};