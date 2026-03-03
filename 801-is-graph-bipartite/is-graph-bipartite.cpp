class Solution {
public:
    bool check(vector<vector<int>>& graph , vector<int> &color ,int n , int src){
        color[src] = 0;
        queue<int> q;
        q.push({src});
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adj : graph[node]){
                if(color[adj] == -1){
                    color[adj] = !color[node];
                    q.push({adj});
                }
                else if(color[adj] == color[node]){
                    return false;
                }

            }

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n , -1);
        for(int i =0;i < n; i++){
            if(color[i] == -1){
                if(!check(graph , color , n , i)) return false;
            }
            
        }
        return true;
    }
};