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


	void shortestPathBfs(int src, int dest) {
		queue<int> q;
		unordered_map<int,bool> visited;
		unordered_map<int,int> parent;

		//initial state
		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();

			for(auto nbr: adj[frontNode]) {
				if(!visited[nbr]) {
					q.push(nbr);
					parent[nbr] = frontNode;
					visited[nbr] = true;
				}
			}
		}

		//parent array tyaar hoga 
		vector<int> ans;
		while(dest != -1) {
			ans.push_back(dest);
			dest = parent[dest];
		}

		reverse(ans.begin(), ans.end());
		//printig the shortest path
		for(auto i: ans) {
			cout << i <<" ";
		}
		
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

	g.shortestPathBfs(src, dest);


	
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