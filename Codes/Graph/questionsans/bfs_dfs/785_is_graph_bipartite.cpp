///////////////bfs/////////
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0 and 1 are two colors

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int nei : graph[node]) {
                        if (color[nei] == -1) {
                            color[nei] = 1 - color[node]; 
                            q.push(nei);
                        } else if (color[nei] == color[node]) {
                            return false; // same color conflict
                        }
                    }
                }
            }
        }
        return true;
    }
};















class Solution {
public:
    bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = c;
        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                bool ok = dfs(nei, 1 - c, color, graph);
                if (ok == false) return false;
            } 
            else if (color[nei] == c) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                bool ok = dfs(i, 0, color, graph);
                if (ok == false) return false;
            }
        }
        return true;
    }
};
