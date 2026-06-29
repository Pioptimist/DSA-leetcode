class Solution {
public:
   vector<int> ans;
   // this is a directed graph since explicitly bol rkha hai kaunsa node kiska parent hai
    bool detect(vector<int> &vis ,vector<int> &path, vector<vector<int>>& prerequisites , int src, int n){
        vis[src] = 1;
        path[src] = 1;
        for(int i = 0; i< n; i++){ //src ko dhundo in prereq and then waha se dfs lgao
        
            if(prerequisites[i][1] == src ){
                if(!vis[prerequisites[i][0]]){
                    if(detect(vis, path , prerequisites , prerequisites[i][0] , n)) return true;
                }
                else if(path[prerequisites[i][0]]) return true;
            }
        }
        path[src] = 0;
        //we make path = 0 when we backtrck ie ki cycle toh nhi bna mtlb yeh safe hai , issi order ko store krlo , aur baad mein reverse krke ans
        ans.push_back(src);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) {
            vector<int> res;
            for(int i = 0 ; i < numCourses ; i++){
                res.push_back(i);
            }
            return res;
        }
        int n = prerequisites.size();
      
        
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i = 0; i< numCourses ; i++ ){
            if(!vis[i]){

                if(detect(vis , path,prerequisites , i , n)) return {};
            }
            
        }
        reverse(ans.begin() , ans.end());

        return ans;
        
    }
};
