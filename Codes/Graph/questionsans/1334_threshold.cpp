#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Initialize distances
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Count reachable cities
        int minReachable = n + 1, city = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            // Choose city with fewer reachable nodes; tie → larger index
            if (count <= minReachable) {
                minReachable = count;
                city = i;
            }
        }

        return city;
    }
};





// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Dijkstra function
//     vector<int> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj) {
//         vector<int> dist(n, INT_MAX);
//         dist[src] = 0;

//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
//         pq.push({0, src});

//         while (!pq.empty()) {
//             auto [d, u] = pq.top();
//             pq.pop();
//             if (d > dist[u]) continue;

//             for (auto &[v, w] : adj[u]) {
//                 if (dist[u] + w < dist[v]) {
//                     dist[v] = dist[u] + w;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }
//         return dist;
//     }

//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         // Step 1: Build adjacency list
//         vector<vector<pair<int,int>>> adj(n);
//         for (auto &e : edges) {
//             int u = e[0], v = e[1], w = e[2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }

//         int minReachable = n + 1, city = -1;

//         // Step 2: Run Dijkstra from each city
//         for (int i = 0; i < n; i++) {
//             vector<int> dist = dijkstra(i, n, adj);
//             int count = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i != j && dist[j] <= distanceThreshold) {
//                     count++;
//                 }
//             }
//             // Step 3: Update result
//             if (count <= minReachable) {
//                 minReachable = count;
//                 city = i;
//             }
//         }

//         return city;
//     }
// };
