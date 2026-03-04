class Solution {
public:
    bool dfs(vector<vector<int>>& graph , vector<int> &vis, vector<int> &path , int n , int src){
        vis[src] = 1;  //assume safe
        path[src] = 1;

        for(int adj : graph[src]){
            if(!vis[adj]){
                if(dfs( graph , vis , path , n , adj)){
                    vis[src] = -1;  //unsafe
                    return true;
                }
            }
            else if(vis[adj] == -1){

                vis[src] = -1;
                return true;
            }
            if(path[adj]){
                vis[src] = -1;  //unsafe
                return true; 
            }
            
        }
        path[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
    
        vector<int> res;
        vector<int> path(n,0);
        vector<int> vis(n,0);

        for(int i =0; i<n ; i++){

            if(!vis[i]){
                dfs(graph , vis ,path,  n , i);

            }
        }

        for(int i=0; i <n ; i++){
            if(vis[i] == 1){
                res.push_back(i);
            }
        }

        return res;

        
    }
};