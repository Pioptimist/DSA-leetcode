class Solution {
public:
    bool detect(vector<int> &vis ,vector<int> &path, vector<vector<int>>& prerequisites , int src, int n, int m){
        vis[src] = 1;
        path[src] = 1;
        for(int i = 0; i< n; i++){
        
            if(prerequisites[i][1] == src ){
                if(!vis[prerequisites[i][0]]){
                    if(detect(vis, path , prerequisites , prerequisites[i][0] , n , m)) return true;
                }
                else if(path[prerequisites[i][0]]) return true;
            }
        }
        path[src] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        int n = prerequisites.size();
        int m = prerequisites[0].size();
        
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i = 0; i< numCourses ; i++ ){
            if(!vis[i]){

                if(detect(vis , path,prerequisites , i , n , m)) return false;
            }
            
        }

        return true;
        
    }
};