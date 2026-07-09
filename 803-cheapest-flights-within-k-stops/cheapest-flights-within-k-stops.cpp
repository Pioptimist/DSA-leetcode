// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
// //this solution works bcz for every stop we are exploring every possible node thru a simple bfs soo at k stop we know no other case can arise.v
//         vector<pair<int, int>> adj[n];
//         for (auto it : flights)
//         {
//             adj[it[0]].push_back({it[1], it[2]});  
//         }

//         queue<pair<int, pair<int, int>>> q;
//         q.push({0, {src, 0}});  
//         vector<int> dist(n, 1e9);
//         dist[src] = 0;  
//         while (!q.empty())
//         {
//             auto it = q.front();
//             q.pop();
//             int stops = it.first;  
//             int node = it.second.first;  
//             int cost = it.second.second;  
           
//             if (stops > k)
//                 break;

           
//             for (auto iter : adj[node])
//             {
//                 int adjNode = iter.first; 
//                 int edW = iter.second;  
//                 if (cost + edW < dist[adjNode] && stops <= k)
//                 {
//                     dist[adjNode] = cost + edW;  
//                     q.push({stops + 1, {adjNode, cost + edW}});  
//                 }
//             }
//         }

       
//         if (dist[dst] == 1e9) return -1;

//         return dist[dst]; 
//     }
// };


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {cost, node, stops}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {

            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst)
                return cost;

            if (stops == k + 1)
                continue;

            if (cost > dist[node][stops])
                continue;

            for (auto [adjNode, wt] : adj[node]) {

                int newCost = cost + wt;

                if (newCost < dist[adjNode][stops + 1]) {

                    dist[adjNode][stops + 1] = newCost;

                    pq.push({newCost, adjNode, stops + 1});
                }
            }
        }

        return -1;
    }
};