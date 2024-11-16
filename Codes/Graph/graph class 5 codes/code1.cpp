   class Solution {
public:
    void topSortBfs(int n, vector<int>& topoOrder,unordered_map<int , list<int> >& adjList) {
		queue<int> q;
		map<int,int> indegree;
		
		//initialise kardi indegree ssanki
		for( auto i : adjList) {
			for(auto nbr: i.second) {
				indegree[nbr]++;
			}
		}
		//push all zero indegree wali node into queue
		for(int node=0; node<n; node++) {
			if(indegree[node] == 0) {
				q.push(node);
			}
		}

		//BFS chalate hai
		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();
			topoOrder.push_back(frontNode);

			for(auto nbr: adjList[frontNode]) {
				indegree[nbr]--;

				//check for zero
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , list<int> > adjList;
        for(vector<int> i: prerequisites) {
            int u = i[0];
            int v = i[1];
            adjList[v].push_back(u);
        }

        vector<int> topoSort;
        topSortBfs(numCourses, topoSort, adjList);
        if(topoSort.size() == numCourses) 
            return true;
        else
            return false;
    }
};

//207 leetcode





// samva123: what is time and space complexity and is there any optimisation available

// GitHub Copilot: ### Time Complexity
// The time complexity of the `topSortBfs` function is \(O(V + E)\), where \(V\) is the number of vertices (nodes) and \(E\) is the number of edges in the graph. This is because:
// 1. Initializing the indegree map takes \(O(E)\) time.
// 2. Pushing all zero indegree nodes into the queue takes \(O(V)\) time.
// 3. The BFS traversal processes each node and edge exactly once, taking \(O(V + E)\) time.

// ### Space Complexity
// The space complexity of the `topSortBfs` function is \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges. This is because:
// 1. The adjacency list 

// adjList

//  takes \(O(E)\) space.
// 2. The indegree map takes \(O(V)\) space.
// 3. The queue can hold up to \(O(V)\) nodes in the worst case.
// 4. The 

// topoOrder

//  vector takes \(O(V)\) space.

// ### Optimizations
// The current implementation is already optimal in terms of time complexity for a topological sort using BFS (Kahn's algorithm). However, some minor improvements can be made for code readability and efficiency:

// 1. Use 

// unordered_map

//  instead of 

// map

//  for 

// indegree

//  to achieve average \(O(1)\) time complexity for insertions and lookups.
// 2. Initialize the 

// indegree

//  map with all nodes to avoid checking for non-existent keys.

// Here is the optimized code:

// ```cpp
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
    void topSortBfs(int n, vector<int>& topoOrder, unordered_map<int, list<int>>& adjList) {
        queue<int> q;
        unordered_map<int, int> indegree;

        // Initialize indegree of all nodes to 0
        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
        }

        // Calculate indegree of each node
        for (auto& i : adjList) {
            for (auto& nbr : i.second) {
                indegree[nbr]++;
            }
        }

        // Push all nodes with zero indegree into the queue
        for (int node = 0; node < n; ++node) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for (auto& nbr : adjList[frontNode]) {
                indegree[nbr]--;

                // Check for zero indegree
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        for (vector<int>& i : prerequisites) {
            adjList[i[1]].push_back(i[0]);
        }

        vector<int> topoOrder;
        topSortBfs(numCourses, topoOrder, adjList);

        return topoOrder.size() == numCourses;
    }
};
// ```

// This code maintains the same time and space complexity but improves readability and efficiency by using 

// unordered_map

//  for 

// indegree

