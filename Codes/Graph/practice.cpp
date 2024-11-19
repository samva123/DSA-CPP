#include<bits/stdc++.h>
using namespace std;

void bfs(int src , unordered_map<int,bool>& vis) {
    queue<int>q;
    q.push(src);

    vis[src] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front;

        for(nbr : adjList[frontNode]){
            int nbrdata = nbr.first;


            if(!)
        }
    }



  
}