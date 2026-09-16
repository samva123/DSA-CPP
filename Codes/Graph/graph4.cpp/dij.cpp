#include <bits/stdc++.h>
using namespace std;

unordered_set<int>allnodes;
vector<vector<pair<int , int>>>adj;

void dij(int src ){
    unordered_map<int, int>dist;
    for(auto node:allnodes ){
        dist[node] = INT_MAX;

    }
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
    pq.push({0,src});
    dist[src] = 0 ;

    while(!pq.empty()){
        auto front = pq.top();
        auto topdist = front.first;
        auto topNode = front.second;
        pq.pop();

        if(topdist > dist[topNode]){
            continue;
        }
        for(auto nbr : adj[topNode]){
            auto nbrNode  = nbr.first;
            auto nbrDist = nbr.second;
            if(topdist + nbrDist < dist[nbrNode]){
                dist[nbrNode] = topdist + nbrDist;
                pq.push({dist[nbrNode] , nbrNode});

            }

        }

    }


}