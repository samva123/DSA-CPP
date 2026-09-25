#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <climits>

using namespace std;

template <typename T>
class Graph {
public:

    // adjacency list
    unordered_map<T, list<pair<T, int>>> adjList;

    // edge list
    vector<tuple<T, T, int>> edges;

    void addEdge(T u, T v, int wt, bool direction) {

        // directed
        if (direction == 1) {
            adjList[u].push_back({v, wt});
            edges.push_back({u, v, wt});
        }

        // undirected
        else {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});

            edges.push_back({u, v, wt});
            edges.push_back({v, u, wt});
        }
    }


    void bellmanFord(T src) {

        unordered_map<T, int> dist;

        // Initialize all vertices
        for (auto &entry : adjList) {
            dist[entry.first] = INT_MAX;

            for (auto &nbr : entry.second) {
                dist[nbr.first] = INT_MAX;
            }
        }

        dist[src] = 0;


        // --------------------------------
        // V - 1 RELAXATIONS
        // --------------------------------

        int V = dist.size();

        for (int i = 1; i <= V - 1; i++) {

            bool anyUpdate = false;

            for (auto &edge : edges) {

                T u = get<0>(edge);
                T v = get<1>(edge);
                int wt = get<2>(edge);

                // Important:
                // Don't relax from an unreachable node
                if (dist[u] != INT_MAX &&
                    dist[u] + wt < dist[v]) {

                    dist[v] = dist[u] + wt;

                    anyUpdate = true;
                }
            }

            // Optimization:
            // If nothing changed, we can stop early.
            if (!anyUpdate)
                break;
        }


        // --------------------------------
        // CHECK NEGATIVE CYCLE
        // --------------------------------

        bool negativeCycle = false;

        for (auto &edge : edges) {

            T u = get<0>(edge);
            T v = get<1>(edge);
            int wt = get<2>(edge);

            if (dist[u] != INT_MAX &&
                dist[u] + wt < dist[v]) {

                negativeCycle = true;
                break;
            }
        }


        // --------------------------------
        // OUTPUT
        // --------------------------------

        if (negativeCycle) {

            cout << "Negative Cycle Present\n";

        }
        else {

            cout << "No Negative Cycle\n";

            cout << "Shortest distances from "
                 << src << ":\n";

            for (auto &entry : dist) {

                cout << src << " -> "
                     << entry.first << " = ";

                if (entry.second == INT_MAX)
                    cout << "INF";

                else
                    cout << entry.second;

                cout << endl;
            }
        }
    }
};









template <typename T>
class Graph {
public:

    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction) {

        // direction -> 0 -> undirected
        // direction -> 1 -> directed

        if(direction == 0) {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        else {
            adjList[u].push_back({v, wt});
        }
    }


    void bellmanFord(T src) {

        // initial state
        unordered_map<T, int> dist;

        // initialize distance of all nodes
        for(auto a : adjList) {

            dist[a.first] = INT_MAX;

            for(auto b : a.second) {
                dist[b.first] = INT_MAX;
            }
        }

        dist[src] = 0;


        // N-1 times -> RELAXATION
        int n = dist.size();

        for(int i = 1; i < n; i++) {

            // traverse on entire edge list
            for(auto a : adjList) {

                for(auto b : a.second) {

                    T u = a.first;
                    T v = b.first;
                    int wt = b.second;

                    if(dist[u] != INT_MAX &&
                       dist[u] + wt < dist[v]) {

                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }


        // check for -ve cycle

        bool anyUpdate = false;

        for(auto a : adjList) {

            for(auto b : a.second) {

                T u = a.first;
                T v = b.first;
                int wt = b.second;

                if(dist[u] != INT_MAX &&
                   dist[u] + wt < dist[v]) {

                    anyUpdate = true;
                    break;
                }
            }

            if(anyUpdate)
                break;
        }


        if(anyUpdate == true) {

            cout << "Negative Cycle Present" << endl;

        }
        else {

            cout << "No Negative Cycle in Graph" << endl;

            cout << "Printing Distance Array: ";

            for(auto i : dist) {
                cout << i.first << " : "
                     << i.second << ", ";
            }

            cout << endl;
        }
    }
};