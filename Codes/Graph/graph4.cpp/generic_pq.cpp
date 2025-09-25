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
        adj[u].push_back(make_pair(v, wt));
        if (!directed) {
            adj[v].push_back(make_pair(u, wt));
        }
    }

    void printAdjList() {
        for (typename unordered_map<T, list<pair<T, int>>>::iterator it = adj.begin(); it != adj.end(); ++it) {
            cout << it->first << " : ";
            for (typename list<pair<T, int>>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
                cout << "(" << jt->first << ", " << jt->second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra(T src, T dest) {
        unordered_map<T, int> dist;
        for (typename unordered_map<T, list<pair<T, int>>>::iterator it = adj.begin(); it != adj.end(); ++it) {
            dist[it->first] = INT_MAX;
        }

        priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            pair<int, T> top = pq.top();
            pq.pop();

            int currDist = top.first;
            T currNode = top.second;

            // Skip outdated distances
            if (currDist > dist[currNode]) continue;

            for (typename list<pair<T, int>>::iterator it = adj[currNode].begin(); it != adj[currNode].end(); ++it) {
                T nbr = it->first;
                int wt = it->second;

                if (currDist + wt < dist[nbr]) {
                    dist[nbr] = currDist + wt;
                    pq.push(make_pair(dist[nbr], nbr));
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
