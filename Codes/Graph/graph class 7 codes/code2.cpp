class Solution {
public:
    void solve(int src, int parent, unordered_map<int,list<int> >& adj, int &timer, 
    vector<vector<int>>& ans,vector<int>& tin,vector<int>& low,unordered_map<int,bool>& vis ) {
        
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;
 
        //nbrs
        for(auto nbr: adj[src]) {
            if(nbr == parent) {
                //ignore this
                continue;
            }
            if(!vis[nbr]) {
                //step1
                solve(nbr, src, adj, timer, ans, tin, low, vis);
                //low update
                low[src] = min(low[src], low[nbr]);
                //bridge testing
                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }

            }
            else {
                //ek or raasta milgya 
                //low update
                low[src] = min(low[src], low[nbr]);
                //no need of bridge testing
            }
        }


    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int> > adj;
        for(auto vec: connections) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //main logic 
        int timer = 1;
        vector<vector<int>> ans;
        vector<int> low(n,0);
        vector<int> tin(n,0);
        int src = 0;
        int parent = -1;
        unordered_map<int,bool> vis;
        solve(src, parent, adj,timer,ans, tin, low,vis);
        return ans;
    }
};



// Time Complexity
// The time complexity of the solve function is (O(V + E)), where (V) is the number of vertices (nodes) and (E) is the number of edges in the graph. This is because:

// Each node is visited exactly once.
// Each edge is considered exactly once during the DFS traversal.
// Space Complexity
// The space complexity of the solve function is (O(V + E)), where (V) is the number of vertices and (E) is the number of edges. This is because:

// The adjacency list adj takes (O(E)) space.
// The tin, low, and vis vectors/maps take (O(V)) space each.
// The recursion stack can go as deep as (O(V)) in the worst case.
// Optimizations
// The current implementation is already optimal in terms of time complexity for finding bridges in a graph using DFS. However, some minor improvements can be made for code readability and efficiency:

// Use vector<bool> instead of unordered_map<int, bool> for vis to achieve average (O(1)) time complexity for insertions and lookups.
// Use vector<int> instead of unordered_map<int, list<int>> for adj if the graph is dense and the nodes are numbered from 0 to (V-1).
// Here is the optimized code:



#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(int src, int parent, vector<vector<int>>& adj, int &timer, 
               vector<vector<int>>& ans, vector<int>& tin, vector<int>& low, vector<bool>& vis) {
        
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;
 
        // Neighbors
        for (auto nbr : adj[src]) {
            if (nbr == parent) {
                // Ignore this
                continue;
            }
            if (!vis[nbr]) {
                // Step 1
                solve(nbr, src, adj, timer, ans, tin, low, vis);
                // Low update
                low[src] = min(low[src], low[nbr]);
                // Bridge testing
                if (low[nbr] > tin[src]) {
                    ans.push_back({src, nbr});
                }
            } else {
                // Another path found
                // Low update
                low[src] = min(low[src], tin[nbr]);
                // No need for bridge testing
            }
        }
    }

    vector<vector<int>> findBridges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<bool> vis(n, false);
        vector<vector<int>> ans;
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                solve(i, -1, adj, timer, ans, tin, low, vis);
            }
        }

        return ans;
    }
};




// Data Structures: Use vector<bool> for vis and vector<vector<int>> for adj to improve efficiency.
// Initialization: Initialize tin, low, and vis vectors with size n.
// Bridge Detection: The findBridges function initializes the necessary data structures and calls the solve function for each unvisited node.
// This optimized code maintains the same time and space complexity but improves readability and efficiency by using more appropriate data structures.
