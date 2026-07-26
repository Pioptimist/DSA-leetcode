class Solution {
public:
    void dfs(int node , vector<vector<int>> &list , vector<bool> &vis){
        vis[node] = 1;

        for(auto it : list[node]){
            if(!vis[it]){
                dfs(it , list , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> list(V , vector<int>(V,0));

        for(int i = 0 ; i < V ; i ++){
            for(int j = 0 ; j  < V ; j++){
                if(isConnected[i][j]==1 && i!=j){
                    list[i].push_back(j);
                }
            }

        }
        vector<bool> vis(V , false);
        int cnt = 0;
        for(int i = 0 ; i< V ; i++){
            if(!vis[i]){
                dfs(i , list , vis);
                cnt++;
            }
        }
        return cnt;
        
    }
};