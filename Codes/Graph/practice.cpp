#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int , vector<pair<int , int>>>adj;
    void addEdge(int u , int v , int wt, bool direction){
        if(direction == 0){
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }else{
            adj[u].push_back({v,wt});
        }


    }
    


};

int main(){

}