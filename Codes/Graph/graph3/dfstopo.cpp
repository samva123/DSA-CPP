#include <iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<stack>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Graph{
	public:
		unordered_map<int,list<int> > adj;

	void addEdge(int u, int v, bool direction) {
		//direction -> 0 undirected 
		//direction -> 1 directed
		if(direction == 1) {
			adj[u].push_back(v);
		}
		else {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	void printAdjList() {
		for(auto i: adj) {
			cout << i.first << ": {";
			for(auto j: i.second) {
				cout << j <<",";
			}
			cout <<"}" << endl;
		}
	}

	void topoSortDfs(int src, map<int,bool> & visited, stack<int>& st) {
		visited[src] = true;

		for(auto nbr: adj[src]) {
			if(!visited[nbr]) {
				topoSortDfs(nbr, visited,st);
			}
		}

		st.push(src);
	}

};



int main() {

	Graph g;
	g.addEdge(0, 5, 0);
	g.addEdge(5, 4, 0);
	g.addEdge(4, 3, 0);
	g.addEdge(0, 6, 0);
	g.addEdge(6, 3, 0);
	g.addEdge(0, 1, 0);
	g.addEdge(1, 2, 0);
	g.addEdge(2, 3, 0);

//int n = 7;
	int src = 0;
	int dest = 3;

	// g.shortestPathBfs(src, dest);


	
	//g.printAdjList();
	// int n = 8;
	// vector<int> topoOrder;
	// g.topSortBfs(n, topoOrder);

	// cout << "Printing the topo Sort ordering: " << endl;
	// for(auto i: topoOrder) {
	// 	cout << i << endl;
	// }

	// if(topoOrder.size() == n) {
	// 	cout << "No Cycle " << endl;
	// }
	// else {
	// 	cout << "Cycle present " << endl;
	// }

	// int n = 8;
	
	// map<int,bool> visited;
	// stack<int> st;
	// for(int node=0; node<n; node++) {
	// 	if(!visited[node] ) {
	// 		g.topoSortDfs(node, visited, st);
	// 	}
	// }
	// cout << "Printing ht topo order:" << endl;
	// while(!st.empty()) {
	// 	cout << st.top();
	// 	st.pop();
	// }



	return 0;
}





///////////////////////////generic dfs 







// #include <iostream>
// #include <unordered_map>
// #include <map>
// #include <list>
// #include <stack>
// #include <algorithm>
// #include <queue>
// #include <vector>
// using namespace std;

// template<typename T>
// class Graph {
// public:
//     unordered_map<T, list<T>> adj;

//     void addEdge(T u, T v, bool direction) {
//         // direction -> 0 undirected 
//         // direction -> 1 directed
//         if (direction == 1) {
//             adj[u].push_back(v);
//         } else {
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//     }

//     void printAdjList() {
//         for (auto i : adj) {
//             cout << i.first << ": {";
//             for (auto j : i.second) {
//                 cout << j << ",";
//             }
//             cout << "}" << endl;
//         }
//     }

//     void topoSortDfs(T src, map<T, bool>& visited, stack<T>& st) {
//         visited[src] = true;

//         for (auto nbr : adj[src]) {
//             if (!visited[nbr]) {
//                 topoSortDfs(nbr, visited, st);
//             }
//         }

//         st.push(src);
//     }
// };

// int main() {
//     Graph<string> g;

//     g.addEdge("A", "B", 1);
//     g.addEdge("B", "C", 1);
//     g.addEdge("A", "D", 1);
//     g.addEdge("D", "C", 1);
//     g.addEdge("E", "F", 1);

//     g.printAdjList();

//     map<string, bool> visited;
//     stack<string> st;

//     // DFS call on all nodes
//     for (auto nodePair : g.adj) {
//         string node = nodePair.first;
//         if (!visited[node]) {
//             g.topoSortDfs(node, visited, st);
//         }
//     }

//     cout << "Printing the Topological Sort ordering (DFS): " << endl;
//     while (!st.empty()) {
//         cout << st.top() << " ";
//         st.pop();
//     }
//     cout << endl;

//     return 0;
// }
