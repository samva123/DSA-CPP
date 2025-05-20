/////////////////////////////////code to convert edgelist to adjacency list///////////////


class Solution {
    public:
      bool checkCycle(int src, unordered_map<int, bool>& vis, int parent, vector<int> adj[]) {
          vis[src] = true;
          
          for (auto nbr : adj[src]) {
              if (nbr == parent) continue;
  
              if (!vis[nbr]) {
                  if (checkCycle(nbr, vis, src, adj)) return true;
              }
              else {
                  return true;
              }
          }
          return false;
      }
  
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Step 1: Convert edge list to adjacency list
          vector<int> adj[V];
          for (auto edge : edges) {
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
              adj[v].push_back(u);  // undirected graph
          }
  
          // Step 2: Use existing DFS logic
          unordered_map<int, bool> vis;
          for (int i = 0; i < V; i++) {
              if (!vis[i]) {
                  if (checkCycle(i, vis, -1, adj)) {
                      return true;
                  }
              }
          }
          return false;
      }
  };

  













  ////////////////////////////code for using vector instead of map for visited///////////

  class Solution {
    public:
      bool checkCycle(int src, vector<bool>& vis, int parent, vector<int> adj[]) {
          vis[src] = true;
  
          for (auto nbr : adj[src]) {
              if (nbr == parent) continue;
  
              if (!vis[nbr]) {
                  if (checkCycle(nbr, vis, src, adj)) return true;
              }
              else {
                  return true;
              }
          }
          return false;
      }
  
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Step 1: Convert edge list to adjacency list
          vector<int> adj[V];
          for (auto edge : edges) {
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
  
          // Step 2: Use vector<bool> instead of unordered_map
          vector<bool> vis(V, false);
          for (int i = 0; i < V; i++) {
              if (!vis[i]) {
                  if (checkCycle(i, vis, -1, adj)) {
                      return true;
                  }
              }
          }
          return false;
      }
  };
  