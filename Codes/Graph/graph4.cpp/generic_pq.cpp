#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <limits.h>
#include <set>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<pair<T, int>>> adj;
    set<T> allNodes;   // keep track of all nodes (sources + sinks)

    void addEdge(T u, T v, int wt, bool direction) {
        allNodes.insert(u);
        allNodes.insert(v);

        if (direction == 1) {
            adj[u].push_back({v, wt});
        }
        else {
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

    void dijkstraShortestDistance(T src) {
        unordered_map<T, int> dist;
        for (auto node : allNodes) {
            dist[node] = INT_MAX;
        }
        dist[src] = 0;

        priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto value = pq.top();
            auto topDist  = value.first;
            auto topNode = value.second;
            pq.pop();

            if (topDist > dist[topNode]) continue;

            for (auto nbrPair : adj[topNode]) {
                T nbrNode = nbrPair.first;
                int edgeWeight = nbrPair.second;

                if (topDist + edgeWeight < dist[nbrNode]) {
                    dist[nbrNode] = topDist + edgeWeight;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        cout << "Shortest Distances from " << src << ":" << endl;
        for (auto node : allNodes) {
            cout << "  " << node << " -> ";
            if (dist[node] == INT_MAX) cout << "INF";
            else cout << dist[node];
            cout << endl;
        }
    }
};

int main() {
    Graph<char> g;

    g.addEdge('A', 'B', 1, 1);
    g.addEdge('A', 'C', 4, 1);
    g.addEdge('B', 'C', 2, 1);
    g.addEdge('B', 'D', 6, 1);
    g.addEdge('C', 'E', 3, 1);
    g.addEdge('C', 'F', 5, 1);
    g.addEdge('D', 'E', 1, 1);
    g.addEdge('E', 'F', 2, 1);

    g.printAdjList();
    cout << endl;

    g.dijkstraShortestDistance('A'); // find shortest paths from A
}



















////////////////////only for majja ///////////
// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <vector>
// #include <queue>
// #include <limits.h>
// #include <set>
// using namespace std;

// template <typename T>
// class Graph {
// public:
//     unordered_map<T, list<pair<T, int>>> adj;
//     set<T> allNodes;   // track all nodes

//     void addEdge(T u, T v, int wt, bool direction) {
//         allNodes.insert(u);
//         allNodes.insert(v);

//         if (direction == 1) {
//             adj[u].push_back({v, wt});
//         }
//         else {
//             adj[u].push_back({v, wt});
//             adj[v].push_back({u, wt});
//         }
//     }

//     void printAdjList() {
//         for (auto i : adj) {
//             cout << i.first << " : { ";
//             for (auto j : i.second) {
//                 cout << "(" << j.first << " , " << j.second << "), ";
//             }
//             cout << "} " << endl;
//         }
//     }

//     void dijkstraWithPath(T src) {
//         unordered_map<T, int> dist;
//         unordered_map<T, T> parent;

//         for (auto node : allNodes) {
//             dist[node] = INT_MAX;
//             parent[node] = '\0';  // null char for "no parent"
//         }
//         dist[src] = 0;

//         priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
//         pq.push({0, src});

//         while (!pq.empty()) {
//             auto [topDist, topNode] = pq.top();
//             pq.pop();

//             if (topDist > dist[topNode]) continue;

//             for (auto nbrPair : adj[topNode]) {
//                 T nbrNode = nbrPair.first;
//                 int edgeWeight = nbrPair.second;

//                 if (topDist + edgeWeight < dist[nbrNode]) {
//                     dist[nbrNode] = topDist + edgeWeight;
//                     parent[nbrNode] = topNode;  // update parent
//                     pq.push({dist[nbrNode], nbrNode});
//                 }
//             }
//         }

//         cout << "Shortest Distances from " << src << ":" << endl;
//         for (auto node : allNodes) {
//             cout << "  " << node << " -> ";
//             if (dist[node] == INT_MAX) cout << "INF";
//             else cout << dist[node];
//             cout << endl;
//         }

//         cout << "\nPaths from " << src << ":" << endl;
//         for (auto node : allNodes) {
//             if (node == src) continue;
//             if (dist[node] == INT_MAX) {
//                 cout << "  " << node << ": No path" << endl;
//                 continue;
//             }

//             // Reconstruct path by backtracking parents
//             vector<T> path;
//             T current = node;
//             while (current != '\0') {
//                 path.push_back(current);
//                 current = parent[current];
//             }
//             reverse(path.begin(), path.end());

//             cout << "  " << node << ": ";
//             for (size_t i = 0; i < path.size(); i++) {
//                 cout << path[i];
//                 if (i + 1 < path.size()) cout << " -> ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Graph<char> g;

//     g.addEdge('A', 'B', 1, 1);
//     g.addEdge('A', 'C', 4, 1);
//     g.addEdge('B', 'C', 2, 1);
//     g.addEdge('B', 'D', 6, 1);
//     g.addEdge('C', 'E', 3, 1);
//     g.addEdge('C', 'F', 5, 1);
//     g.addEdge('D', 'E', 1, 1);
//     g.addEdge('E', 'F', 2, 1);

//     g.printAdjList();
//     cout << endl;

//     g.dijkstraWithPath('A'); // run Dijkstra from A
// }
