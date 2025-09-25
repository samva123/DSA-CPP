 //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool checkCyclic(int src, unordered_map<int,bool>& vis,
        unordered_map<int,bool> &dfsTrack,vector<int> adj[] ) {
            
        vis[src] = true;
        dfsTrack[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!vis[nbr]) {
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                if(ans == true) {
                    return true;
                }
            }
            if(vis[nbr]==1 && dfsTrack[nbr]==1) {
                //cycle present
                return true;
            }
        }
        
        
        //backtrack - [yahi galti karta hu]
        dfsTrack[src] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       unordered_map<int,bool> vis;
       unordered_map<int,bool> dfsTrack;
       
       for(int node=0; node<V; node++) {
           if(!vis[node]) {
               bool isCyclic = checkCyclic(node, vis, dfsTrack, adj);
               if(isCyclic) {
                   return true;
               }
           }
       }
       return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends



#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkCyclic(int src, vector<bool>& vis, vector<bool>& dfsTrack, vector<int> adj[]) {
        vis[src] = true;
        dfsTrack[src] = true;
        
        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                if (ans) {
                    return true;
                }
            } else if (dfsTrack[nbr]) {
                // Cycle present
                return true;
            }
        }
        
        // Backtrack
        dfsTrack[src] = false;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> dfsTrack(V, false);
       
        for (int node = 0; node < V; node++) {
            if (!vis[node]) {
                if (checkCyclic(node, vis, dfsTrack, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);

    if (sol.isCyclic(V, adj)) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Graph doesn't contain cycle" << endl;
    }

    return 0;
}