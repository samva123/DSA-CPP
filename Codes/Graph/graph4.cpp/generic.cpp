#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;

// Generic Graph class
template <typename T>
class Graph {
public:
    unordered_map<T, list<pair<T, int>>> adj;

    void addEdge(T u, T v, int wt, bool direction) {
        // direction - 0 - undirected
        // direction - 1 - directed
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

    void topoOrderDfs(T src, stack<T>& topo, unordered_map<T, bool>& visited) {
        visited[src] = true;

        for (auto nbrPair : adj[src]) {
            T nbrNode = nbrPair.first;
            if (!visited[nbrNode]) {
                topoOrderDfs(nbrNode, topo, visited);
            }
        }

        topo.push(src);
    }

    void shortestPathDfs(stack<T>& topoOrder, unordered_map<T, int>& dist) {
        // Initially, maintain src
        T src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        for (auto nbrPair : adj[src]) {
            T nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (dist[src] + nbrDist < dist[nbrNode]) {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        while (!topoOrder.empty()) {
            T src = topoOrder.top();
            topoOrder.pop();

            for (auto nbrPair : adj[src]) {
                T nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (dist[src] + nbrDist < dist[nbrNode]) {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        cout << "Printing the distance map:" << endl;
        for (auto i : dist) {
            cout << i.first << " -> " << i.second << endl;
        }
    }

    void dijkstraShortestDistance(T src, T dest) {
        unordered_map<T, int> dist;
        for (auto i : adj) {
            dist[i.first] = INT_MAX;
        }
        set<pair<int, T>> st;

        // Initial state -> (0, src)
        st.insert({0, src});
        dist[src] = 0;

        while (!st.empty()) {
            auto topElement = st.begin();
            pair<int, T> topPair = *topElement;
            int topDist = topPair.first;
            T topNode = topPair.second;
            st.erase(st.begin());

            for (pair<T, int> nbrPair : adj[topNode]) {
                T nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (topDist + nbrDist < dist[nbrNode]) {
                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if (previousEntry != st.end()) {
                        st.erase(previousEntry);
                    }
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        cout << "Shortest Distance from " << src << " Node to " << dest << " Node: " << dist[dest] << endl;
    }
};


int main() {
    Graph<char> g;
    g.addEdge('A', 'B', 1, 1);
    g.addEdge('B', 'C', 2, 1);
    g.addEdge('A', 'C', 4, 1);
    g.printAdjList();

    unordered_map<char, bool> visited;
    stack<char> topo;
    for (auto node : g.adj) {
        if (!visited[node.first]) {
            g.topoOrderDfs(node.first, topo, visited);
        }
    }

    unordered_map<char, int> dist;
    for (auto node : g.adj) {
        dist[node.first] = INT_MAX;
    }

    g.shortestPathDfs(topo, dist);

    g.dijkstraShortestDistance('A', 'C');
}
