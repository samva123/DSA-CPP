#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        sort(edges.begin(), edges.end(), comp);
        //instead of this we can use this 
        // sort(edges.begin(), edges.end(), [&](auto &a, auto &b){
        //     return a[2] < b[2];
        // });



        DisjointSet ds(V);
        int mst = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mst += w;
                ds.unionBySize(u, v);
            }
        }
        return mst;
    }
};
