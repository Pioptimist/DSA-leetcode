class Solution {
public:
    //this solution works bcz for every stop we are exploring every possible node thru a simple bfs soo we are exploring every possible path with x stops. keep in mind a simple bfs wont work on weighted graph for edge relaxation , here it is bcz we are treating stops as level , we process stops = 0 , stops = 1 , stops =2... like this and keep updating dist , we will keep coming across same nodes hce we can relax their wt
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});  
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});  
        vector<int> dist(n, 1e9);
        dist[src] = 0;  
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;  
            int node = it.second.first;  
            int cost = it.second.second;  
           
            if (stops == k+1) break;

            for (auto iter : adj[node])
            {
                int adjNode = iter.first; 
                int edW = iter.second;  
                if (cost + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edW;  
                    q.push({stops + 1, {adjNode, cost + edW}});  
                }
            }
        }

       
        if (dist[dst] == 1e9) return -1;

        return dist[dst]; 
    }
};


// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights,
//                           int src, int dst, int k) {

//         vector<vector<pair<int,int>>> adj(n);

//         for (auto &it : flights) {
//             adj[it[0]].push_back({it[1], it[2]});
//         }

//         // {cost, node, stops}
//         priority_queue<
//             tuple<int,int,int>,
//             vector<tuple<int,int,int>>,
//             greater<tuple<int,int,int>>
//         > pq;

//         vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

//         dist[src][0] = 0;
//         pq.push({0, src, 0});

//         while (!pq.empty()) {

//             auto [cost, node, stops] = pq.top();
//             pq.pop();

//             if (node == dst)
//                 return cost;

//             if (stops == k + 1)
//                 continue;

//             if (cost > dist[node][stops])
//                 continue;

//             for (auto [adjNode, wt] : adj[node]) {

//                 int newCost = cost + wt;

//                 if (newCost < dist[adjNode][stops + 1]) {

//                     dist[adjNode][stops + 1] = newCost;

//                     pq.push({newCost, adjNode, stops + 1});
//                 }
//             }
//         }

//         return -1;
//     }
// };
//the above code is when we consider stops as a state too also here we take dist col as k+2 bcz
// dist[node][flights] = minimum cost to reach 'node' using exactly 'flights' flights.
// Maximum allowed flights = k + 1 (since k stops means k+1 flights),
// so flights can range from 0 to k+1, requiring k+2 columns.

//since reaching same number with diff number of stops is a dff state hence we do a multi state djikstra in here hence the dist[][k]



//in graphs we use and think of dp when we are given a DAG or a external parameter like stops in this question which helps us avoid cycles as a state is defined as stops and dest , we can think of dp in this ques easily like :

// class Solution {
//     int memo[105][105]; // memo[node][stops_left]
//     const int INF = 1e9;

//     int solve(int u, int dst, int stops_left, vector<vector<pair<int, int>>>& adj) {
//       
//         if (u == dst) return 0;    // Reached the destination

//         
//         if (stops_left == 0) return INF; // No more stops/flights allowed

//         if (memo[u][stops_left] != -1) return memo[u][stops_left];

//         int minCost = INF;

//         // Explore all outgoing flights
//         for (auto& edge : adj[u]) {
//             int v = edge.first;
//             int price = edge.second;

//             // Recurse with stops_left - 1
//             int nextCost = solve(v, dst, stops_left - 1, adj);
//             if (nextCost != INF) {
//                 minCost = min(minCost, price + nextCost);
//             }
//         }

//         return memo[u][stops_left] = minCost;
//     }

// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         // Build adjacency list: u -> {v, price}
//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& f : flights) {
//             adj[f[0]].push_back({f[1], f[2]});
//         }

//         memset(memo, -1, sizeof(memo));

//         // At most k stops means at most (k + 1) edges / flights
//         int ans = solve(src, dst, k + 1, adj);

//         return (ans >= INF) ? -1 : ans;
//     }
// };

//bottoms up :
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         const int INF = 1e9;
//         int maxFlights = k + 1;

//         // dp[s][u] = min cost to reach dst from node u using AT MOST s flights
//         vector<vector<int>> dp(maxFlights + 1, vector<int>(n, INF));

        
//         for (int s = 0; s <= maxFlights; s++) {
//             dp[s][dst] = 0; //base case , cost of dist to dist is 0 always
//         }

        
//         for (int s = 1; s <= maxFlights; s++) {
            
//             for (int u = 0; u < n; u++) {
//                 if (u == dst) continue;

//                 dp[s][u] = dp[s - 1][u];  //humko atmost s flights bola hai toh hum bol skte hai ki dp[s][u] will be atleast dp[s - 1][u] ie jo s - 1 se ans hai woh s ke liye toh rhega hi , ab aage jake koi better mil gya toh update
//             }

           
//             for (const auto& flight : flights) {
//                 int u = flight[0];
//                 int v = flight[1];
//                 int price = flight[2];

//                 if (dp[s - 1][v] != INF) {
//                     dp[s][u] = min(dp[s][u], price + dp[s - 1][v]);
//                 }
//             }
//         }

        
//         return dp[maxFlights][src] >= INF ? -1 : dp[maxFlights][src];
//     }
// };