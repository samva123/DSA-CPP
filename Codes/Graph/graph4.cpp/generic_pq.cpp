#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<pair<T, int>>> adj;

    void addEdge(T u, T v, int wt, bool directed) {
        adj[u].push_back({v, wt});
        if (!directed) {
            adj[v].push_back({u, wt});
        }
    }

    void printAdjList() {
        for (auto& node : adj) {
            cout << node.first << " : ";
            for (auto& nbr : node.second) {
                cout << "(" << nbr.first << ", " << nbr.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra(T src, T dest) {
        unordered_map<T, int> dist;
        for (auto& node : adj) {
            dist[node.first] = INT_MAX;
        }

        priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            // Skip outdated distances
            if (currDist > dist[currNode]) continue;

            for (auto& [nbr, wt] : adj[currNode]) {
                if (currDist + wt < dist[nbr]) {
                    dist[nbr] = currDist + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        cout << "Shortest Distance from " << src << " to " << dest << " is: " << dist[dest] << endl;
    }
};
int main() {
    Graph<char> g;
    g.addEdge('A', 'B', 1, true);
    g.addEdge('B', 'C', 2, true);
    g.addEdge('A', 'C', 4, true);

    g.printAdjList();
    g.dijkstra('A', 'C');

    return 0;
}
