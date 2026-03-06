class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long INF = 1e18;
        const int MOD = 1e9+7;

        vector<vector<pair<int,int>>> adj(n);
        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // Step 1: Dijkstra
        vector<long long> dist(n, INF);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v,w] : adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 2: build shortest path DAG
        vector<vector<int>> dag(n);

        for(auto &r : roads){
            int u = r[0], v = r[1], w = r[2];

            if(dist[u] + w == dist[v])
                dag[u].push_back(v);

            if(dist[v] + w == dist[u])
                dag[v].push_back(u);
        }

        // Step 3: DFS + memo to count paths
        vector<long long> dp(n, -1);

        function<long long(int)> dfs = [&](int node){
            if(node == n-1) return 1LL;

            if(dp[node] != -1) return dp[node];

            long long ways = 0;

            for(int nxt : dag[node]){
                ways = (ways + dfs(nxt)) % MOD;
            }

            return dp[node] = ways;
        };

        return dfs(0);
    }
};