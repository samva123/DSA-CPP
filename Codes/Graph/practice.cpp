#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    public:

    unordered_map<int , list<int>>adj;
    void addEdge(int u , int v  , bool direction){
        if(direction == 1){
            adj[u].push_back(v);
        }
        else{
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        cout << endl;
        printadj();

    }

    void printadj(){
        for(auto i : adj){
            cout << i.first << " : {" ;
            for(auto nbr : i.second){
                cout << nbr << ",";
            }
            cout << "}";
        }

    }


    void bfs(T src , unordered_map<T , bool>&vis){

        queue<T>q;

        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            T frontNode  = q.front();
            cout << frontNode;

            for(auto nbr : adj[frontNode]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }

    }

};