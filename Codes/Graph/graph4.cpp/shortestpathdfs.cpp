#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

// Directed and weighted graph
class Graph {
public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int wt, bool direction) {
        // direction = 1 → directed, 0 → undirected
        if (direction == 1) {
            adj[u].push_back({v, wt});
        } else {
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " : { ";
            for (auto j : i.second) {
                cout << "(" << j.first << " , " << j.second << "), ";
            }
            cout << "} " << endl;
        }
    }

    void topoOrderDfs(int src, stack<int>& topo, unordered_map<int,bool>& visited) {
        visited[src] = true;
        for (auto nbrPair : adj[src]) {
            int nbrNode = nbrPair.first;
            if (!visited[nbrNode]) {
                topoOrderDfs(nbrNode, topo, visited);
            }
        }
        topo.push(src);
    }

    void shortestPathDfs(stack<int>& topoOrder, int n, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!topoOrder.empty()) {
            int u = topoOrder.top();
            topoOrder.pop();

            if (dist[u] != INT_MAX) { // relax only if reachable
                for (auto nbrPair : adj[u]) {
                    int v = nbrPair.first;
                    int wt = nbrPair.second;
                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        cout << "Printing the distance array: " << endl;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    int n = 6; // number of nodes

    // Build a weighted DAG
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(1, 3, 6, 1);
    g.addEdge(1, 2, 2, 1);
    g.addEdge(2, 4, 4, 1);
    g.addEdge(2, 5, 2, 1);
    g.addEdge(2, 3, 7, 1);
    g.addEdge(3, 4, -1, 1);
    g.addEdge(4, 5, -2, 1);

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    // Step 1: Topological sort
    stack<int> topo;
    unordered_map<int,bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.topoOrderDfs(i, topo, visited);
        }
    }

    // Step 2: Shortest path from source (0)
    g.shortestPathDfs(topo, n, 0);

    return 0;
}
