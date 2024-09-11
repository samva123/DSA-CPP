#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph {
  public:
    unordered_map<int, list<int> > adjList;
    void addEdge(int u, int v, bool direction) {
      //direction -> 0 -> undirected
      //direction -> 1 -> directed
      if(direction == 1) {
        adjList[u].push_back(v);
      }
      else {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }
      cout << endl << "printing adjList" << endl;
      printAdjList();
      cout << endl;
    }
    void printAdjList() {
      for(auto i: adjList) {
        cout << i.first << "-> {";
        for(auto neighbour: i.second) {
          cout << neighbour <<", ";
        }
        cout << "}" << endl;
      }
    }
       bool solve(int src) {
        queue<int> q;
      
      unordered_map<int,int> parent;
      unordered_map<int,bool> visited;
      //intiial state
      int src = 0;
      q.push(src);
      visited[src] = true;
      parent[src] = -1; 

      while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for(auto nbr: adjList[frontNode]) {
        //    if(nbr == parent[frontNode]) {
        //         continue;
        //     }
          if(!visited[nbr]) {
            q.push(nbr);
            visited[nbr] = true;
            parent[nbr] = frontNode;
          }
          else if(visited[nbr] == true && nbr != parent[frontNode]) {
            //cycle present 
            // cout << "nbr: " << nbr << endl;
            // cout << "frontNode: " << frontNode << endl;
            // cout << "parent[nbr]: " << parent[nbr] << endl;
            return true;
          }
        }
      }
      //cycle not present
      return false;
    }
};

// // } Driver Code Ends
// class Solution {
//   public:
//     // Function to detect cycle in an undirected graph.
    
 
// };
