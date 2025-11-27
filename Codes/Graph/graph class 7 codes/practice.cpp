#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    public:
    unordered_map<T , list<pair<T,int>>> adjList;
    set<T> nodes;

    void addEdge(T u , T v , int wt , bool direction){
        nodes.insert(u);
        nodes.insert(v);

        if(direction == 0){
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }else{
            adjList[u].push_back({v,wt});
        }
    }

    void bellmanFord(T src){
        unordered_map<T , int> dist;

        for(auto node: nodes){
            dist[node] = INT_MAX;
        }
        dist[src] = 0;

        int n = nodes.size();

        // relaxation n-1 times
        for(int i = 1; i <= n-1; i++ ){
            for(auto a : adjList){
                for(auto b : a.second){
                    T u = a.first;
                    T v = b.first;
                    int wt = b.second;

                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        bool anyUpdate = false;

        for(auto a : adjList){
            for(auto b : a.second){
                T u = a.first;
                T v = b.first;
                int wt = b.second;

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    anyUpdate = true;
                    break;
                }
            }
            if(anyUpdate) break;
        }

        if(anyUpdate == true){
            cout << "Negative cycle present";
        }else{
            cout << "Everything is fine";
        }
    }

    
};


int main() {
    Graph<int> g;

    g.addEdge(1, 2, 1, 1);    
    g.addEdge(2, 3, -1, 1);   
    g.addEdge(3, 1, -1, 1);   

    g.bellmanFord(1);
    return 0;
}
