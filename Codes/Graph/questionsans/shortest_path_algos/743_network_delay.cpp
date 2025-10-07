
///////////////////////////most  optimised///////


// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         // adjacency list using fixed-size array of vectors
//         vector<pair<int,int>> adj[n+1];

//         // build graph
//         for (auto &e : times) {
//             int u = e[0], v = e[1], wt = e[2];
//             adj[u].push_back({v, wt});
//         }

//         // distance array
//         vector<int> dist(n+1, INT_MAX);
//         vector<bool> visited(n+1, false);

//         // min-heap for Dijkstra
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
//         dist[k] = 0;
//         pq.push({0, k});

//         while (!pq.empty()) {
//             auto [currdist, node] = pq.top();
//             pq.pop();

//             if (visited[node]) continue;
//             visited[node] = true;
////////////////can also use currdist > dist[node] instead of the whole visted thing 

//             for (auto [v, wt] : adj[node]) {
//                 if (currdist + wt < dist[v]) {
//                     dist[v] = currdist + wt;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }

//         int ans = *max_element(dist.begin() + 1, dist.end());
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

//////////////////when revising ask chatgpt what is benefit of vector<vector< in this question
/////////////////instead of vector<pair<int , int>>