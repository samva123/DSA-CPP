#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// class Graph {
//   public:
//     unordered_map<int, list<int> > adjList;
//     void addEdge(int u, int v, bool direction) {
//       //direction -> 0 -> undirected
//       //direction -> 1 -> directed
//       if(direction == 1) {
//         adjList[u].push_back(v);
//       }
//       else {
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//       }
//       cout << endl << "printing adjList" << endl;
//       printAdjList();
//       cout << endl;
//     }
//     void printAdjList() {
//       for(auto i: adjList) {
//         cout << i.first << "-> {";
//         for(auto neighbour: i.second) {
//           cout << neighbour <<", ";
//         }
//         cout << "}" << endl;
//       }
//     }
// };

//unordered_map<int , list<int>>adjList;


template <typename T>
class Graph {
  public:
    unordered_map<T, list<pair<T,int> > > adjList;

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

    void bfsTraversal(T src,unordered_map< T, bool>& vis) {
      //adjList alrady data member me hai 
      //visited
      
      //queue
      queue<T> q;

      //initial state
      q.push(src);
      vis[src] =true;

      while(!q.empty()) {
        T frontNode = q.front();
        cout << frontNode << " ";
        q.pop();

        //go to nbr
        for(auto nbr: adjList[frontNode]) {
          T nbrData = nbr.first;

          if(!vis[nbrData]) {
            vis[nbrData] = true;
            q.push(nbrData);
            
          }
        }
      }

    }

    void dfs(T src, unordered_map<T,bool>& vis ) {
      vis[src] = true;
      cout << src << " ";

      for(auto nbr: adjList[src]) {
        T nbrData = nbr.first;
        if(!vis[nbrData]) {
          dfs(nbrData, vis);
        }
      }
    }

};

int main() {
//   Graph g;
//   g.addEdge(0,1,0);
//   g.addEdge(1,2,0);
//   g.addEdge(1,3,0);
//   g.addEdge(2,3,0);

  Graph<char> g;
 // cout << "HII" << endl;
  g.addEdge('a','b',5,1);
  g.addEdge('a','c',10,1);
  g.addEdge('b','c',20,1);

  //g.addEdge('c','e',20,1);
  g.addEdge('e','f',50,1);
  g.addEdge('f','d',50,1);

  unordered_map<char, bool> vis;
  //g.dfs('a',visited);
  int count = 0;
  for(char node='a'; node<='f'; node++) {
    if(!vis[node]) {
      count++;
      g.dfs(node, vis);
    }
  }
  cout << endl << "Number of disconnected components: " << count << endl;
  //HW: find out number of disconnected components in a graph
  vis.clear();
  

  // unordered_map<char, bool> vis;
  for(char node='a'; node<='f'; node++) {
      if(!vis[node] ) {
        g.bfsTraversal(node,vis);
      }
  }

  
  return 0;
}



// DFS (Depth-First Search):

// Explores as far as possible along each branch before backtracking.
// Uses a stack (either explicitly or via recursion).
// Typically implemented using recursion or an explicit stack.
// Visits nodes in a depthward motion.
// BFS (Breadth-First Search):

// Explores all neighbors at the present depth prior to moving on to nodes at the next depth level.
// Uses a queue.
// Typically implemented using an explicit queue.
// Visits nodes in a level-order motion.