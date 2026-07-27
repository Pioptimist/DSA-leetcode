class Solution {
public:
//logic is simple , agr koi bhi node kisi loop ka part hai then it is not at all safe , those nodes which are not part of loop will be marked 1 , and the ones which are will be marked -1
    bool dfs(vector<int> &vis , vector<int>& path ,int node, vector<vector<int>>& graph){
        vis[node] = 1;
        path[node] = 1;

        for(int adj : graph[node]){
            if(!vis[adj]){
                if(dfs(vis , path , adj , graph)){    //curr node loop ka part hai
                    vis[node] = -1;
                    return true;
                }
            }
            else if(vis[adj] == -1){
                vis[node] = -1;   //agr adj node , loop ka part hai then again we can say curr node bhi hai, this case is when a diff node is joining to a cycle
                return true;
            }
            else if(path[adj]){
                vis[node] = -1;  //same node wapis same pe wapis mil gya
                return true;
            }
            
        }
        path[node] = 0;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n , 0);
        vector<int> path(n , 0);
        vector<int> res;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(vis , path , i , graph );
            }    

        }

        for(int i = 0 ; i< n ; i++){
            if(vis[i] == 1) res.push_back(i);
        }
        return res;

        
    }
};