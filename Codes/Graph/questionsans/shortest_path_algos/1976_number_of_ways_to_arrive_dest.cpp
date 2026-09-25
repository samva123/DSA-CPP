 



















////////////////////it is very slow just wrote for one extra approach//////////


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF = 1e18;
        const int MOD = 1'000'000'007;

        vector<long long> dist(n, INF);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // Relax edges n-1 times
        for (int i = 0; i < n - 1; i++) {
            bool changed = false;
            for (auto &r : roads) {
                int u = r[0], v = r[1], w = r[2];
                
                // If going u -> v improves
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];  // overwrite
                    changed = true;
                } else if (dist[u] + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // add more paths
                }

                // Same for v -> u
                if (dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    ways[u] = ways[v];
                    changed = true;
                } else if (dist[v] + w == dist[u]) {
                    ways[u] = (ways[u] + ways[v]) % MOD;
                }
            }
            if (!changed) break; // early stop
        }

        return ways[n - 1] % MOD;
    }
};
