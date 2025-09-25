#include <bits/stdc++.h>
using namespace std;



template <typename T>
class Graph {
  public:
    unordered_map<T, list<pair<T,int> > > adjList;

    // void addEdge(T u, T v,  bool direction) {
    //   if(direction == 1) {
    //     adjList[u].push_back();
    //   }
    //   else {
    //     adjList[u].push_back(v);
    //     adjList[v].push_back(u);
    //   }
    //   printAdjList();
    // cout << endl;
    // }


    void addEdge(T u, T v, int wt, bool direction) {
      if(direction == 1) {
        adjList[u].push_back(make_pair(v,wt));
      }
      else {
        adjList[u].push_back({v,wt});
        adjList[v].push_back({u,wt});
      }
      printAdjList();
    cout << endl;
    }
    

    void printAdjList() {
      for(auto i: adjList) {
        cout << i.first <<": {  ";
        for(auto p: i.second) {
          cout << "{"<<p.first <<", "<<p.second <<"}, ";
        }
        cout<<"}" << endl;
      }
    }

//     void bellmanFord( T src, int n) {
//     // Initialize distances
//     map<T, int> dist;
//     for (auto nodePair : adjList) {
//         dist[nodePair.first] = INT_MAX;
//     }
//     dist[src] = 0;

//     // Relaxation for N-1 times
//     for (int i = 1; i <= n - 1; i++) {
//         for (auto a : adjList) {
//             T u = a.first;
//             for (auto b : a.second) {
//                 T v = b.first;
//                 int wt = b.second;
//                 if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
//                     dist[v] = dist[u] + wt;
//                 }
//             }
//         }
//     }

//     // Check for negative cycle
//     bool anyUpdate = false;
//     for (auto a : adjList) {
//         T u = a.first;
//         for (auto b : a.second) {
//             T v = b.first;
//             int wt = b.second;
//             if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
//                 anyUpdate = true;
//                 break;
//             }
//         }
//         if (anyUpdate) break;
//     }

//     // Output
//     if (anyUpdate) {
//         cout << "Negative Cycle Present" << endl;
//     } else {
//         cout << "No Negative Cycle in Graph" << endl;
//         cout << "Printing Distance Array: ";
//         for (auto d : dist) {
//             cout << "[" << d.first << "] -> " << d.second << ", ";
//         }
//         cout << endl;
//     }
// }
































// //template <typename T>
// void dfs1(T node, stack<T>& ordering, unordered_map<T, bool>& vis, unordered_map<T, list<T>>& adjList) {
//     vis[node] = true;
//     for (auto nbr : adjList[node]) {
//         if (!vis[nbr]) {
//             dfs1(nbr, ordering, vis, adjList);
//         }
//     }
//     // Push in stack after exploring completely
//     ordering.push(node);
// }

// //template <typename T>
// void dfs2(T src, unordered_map<T, bool>& vis2, unordered_map<T, list<T>>& adjNew) {
//     vis2[src] = true;
//     cout << src << "; ";

//     for (auto nbr : adjNew[src]) {
//         if (!vis2[nbr]) {
//             dfs2(nbr, vis2, adjNew);
//         }
//     }
// }

// //template <typename T>
// int getStronglyConnectedComponents(unordered_map<T, list<T>>& adjList) {
//     // Step 1: get the ordering
//     stack<T> ordering;
//     unordered_map<T, bool> vis;

//     for (auto nodePair : adjList) {
//         T node = nodePair.first;
//         if (!vis[node]) {
//             dfs1(node, ordering, vis, adjList);
//         }
//     }

//     // Step 2: reverse edges
//     unordered_map<T, list<T>> adjNew;
//     for (auto a : adjList) {
//         for (auto b : a.second) {
//             T u = a.first;
//             T v = b;
//             // v -> u entry
//             adjNew[v].push_back(u);
//         }
//     }

//     // Step 3: traverse using ordering and count components
//     int count = 0;
//     unordered_map<T, bool> vis2;

//     while (!ordering.empty()) {
//         T node = ordering.top();
//         ordering.pop();
//         if (!vis2[node]) {
//             cout << "SCC #" << count + 1 << ": ";
//             dfs2(node, vis2, adjNew);
//             count++;
//             cout << endl;
//         }
//     }

//     return count;
// }








































// template<typename T>
// void floydWarshall(vector<T>& nodes) {
//     int n = nodes.size();

//     // Step 1: Map node T → index
//     unordered_map<T, int> nodeToIndex;
//     for (int i = 0; i < n; i++) {
//         nodeToIndex[nodes[i]] = i;
//     }

//     // Step 2: Initialize distance matrix
//     vector<vector<int>> dist(n, vector<int>(n, 1e9));

//     // Step 3: Diagonal = 0
//     for (int i = 0; i < n; i++) {
//         dist[i][i] = 0;
//     }

//     // Step 4: Initialize distances for edges
//     for (auto a : adjList) {
//         for (auto b : a.second) {
//             T u = a.first;
//             T v = b.first;
//             int wt = b.second;
//             int ui = nodeToIndex[u];
//             int vi = nodeToIndex[v];
//             dist[ui][vi] = wt;
//         }
//     }

//     // Step 5: Main logic - Floyd-Warshall
//     for (int helper = 0; helper < n; helper++) {
//         for (int src = 0; src < n; src++) {
//             for (int dest = 0; dest < n; dest++) {
//                 if (dist[src][helper] < 1e9 && dist[helper][dest] < 1e9) {
//                     dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
//                 }
//             }
//         }
//     }

//     // Step 6: Print distance matrix
//     cout << "All-Pairs Shortest Path Matrix:" << endl;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (dist[i][j] == 1e9)
//                 cout << "INF ";
//             else
//                 cout << dist[i][j] << " ";
//         }
//         cout << endl;
//     }
// }








//template<typename T>
void floydWarshall() {
    set<T> allNodes;
    
    // Add all source nodes
    for (auto nodePair : adjList) {
        allNodes.insert(nodePair.first);
    }
    
    // Add all destination nodes
    for (auto a : adjList) {
        for (auto b : a.second) {
            allNodes.insert(b.first);
        }
    }
    
    // Convert to vector and sort
    vector<T> nodes(allNodes.begin(), allNodes.end());
    int n = nodes.size();
    
    // Rest of your Floyd-Warshall code remains the same...
    unordered_map<T, int> nodeToIndex;
    for (int i = 0; i < n; i++) {
        nodeToIndex[nodes[i]] = i;
    }


    // Step 2: Initialize distance matrix
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    // Step 3: Diagonal = 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Step 4: Initialize distances for edges
    for (auto a : adjList) {
        for (auto b : a.second) {
            T u = a.first;
            T v = b.first;
            int wt = b.second;
            int ui = nodeToIndex[u];
            int vi = nodeToIndex[v];
            dist[ui][vi] = wt;
        }
    }

    // Step 5: Main logic - Floyd-Warshall
    for (int helper = 0; helper < n; helper++) {
        for (int src = 0; src < n; src++) {
            for (int dest = 0; dest < n; dest++) {
                if (dist[src][helper] < 1e9 && dist[helper][dest] < 1e9) {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }
    }

    // Step 6: Print distance matrix
    cout << "All-Pairs Shortest Path Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 1e9)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}






    

};




int main() {
	Graph<int>g;
	// g.addEdge(0, 1, 1);
	// g.addEdge(1, 2, 1);
	// g.addEdge(2, 3, 1);
	// g.addEdge(3, 0, 1);

	// g.addEdge(2, 4, 1);

	// g.addEdge(4, 5, 1);
	// g.addEdge(5, 6, 1);
	// g.addEdge(6, 4, 1);


    

	// g.addEdge(6, 7, 1);
	//int n = 8;
//   int ans = g.getStronglyConnectedComponents(n);
//   cout << "SCC Count: " << ans << endl;

    g.addEdge(0, 1, 3, 1);
	g.addEdge(1, 0, 2, 1);
	g.addEdge(0, 3, 5, 1);
	g.addEdge(1, 3, 4, 1);
	g.addEdge(3, 2, 2, 1);
	g.addEdge(2, 1, 1, 1);
	g.floydWarshall();

	//cout << "hello "<<endl;
	// g.addEdge('A','B', -1,1);
	// g.addEdge('B','E', 2,1);
	// g.addEdge('E','D', -3,1);
	// g.addEdge('D','C', 5,1);
	// g.addEdge('A','C', 4,1);
	// g.addEdge('B','C', 3,1);
	// g.addEdge('B','D', 2,1);
	// g.addEdge('D','B', 1,1);
	// g.printAdjList();
    // g.bellmanFord('A',5);

	return 0;
}