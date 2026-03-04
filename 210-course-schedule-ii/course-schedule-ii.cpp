class Solution {
public:
    vector<int> res;
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;
        for(int nei : adj[node]) {
            if(!vis[nei]) {
                if(dfs(nei, adj, vis, path))
                    return true;   
            }
            else if(path[nei]) {
                return true;       
            }
        }

        path[node] = 0;           
        res.push_back(node);      
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);  
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, path))
                    return {};     
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
