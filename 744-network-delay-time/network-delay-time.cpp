class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int,int>>> adj(n+1);     // n+1 bcz this is 1 indexed
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> dist(n+1,1e9);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjWeight=it.second;
                if(distance + adjWeight < dist[adjNode]){
                    dist[adjNode] = distance + adjWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        int ans = 0;
        for(int i =1 ;i<n+1;i++){
            if(dist[i]==1e9) return -1;

            ans = max(ans,dist[i]);
        }

        return ans;
        
    }
};