#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int> > > adjList;
    unordered_set<T>nodes;

    void addEdge(T u, T v, int wt, bool direction) {
        nodes.insert(u);
        nodes.insert(v);
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






    void dijkastra(T src){
        vector<T>dist(nodes.size());
        for(int i = 0 ; i < nodes.size() ; i++){
            dist[i] = INT_MAX;
        }
        set<pair<int , T>>st;
        st.insert({0,src});
        dist[src] = 0 ;

        while(!st.empty()){
            auto topelement  = st.begin();
            auto topPair  = *topelement;
            auto topDist = toppair.first;
            auto topNode  = toppair.second;
            st.erase(st.begin());

            if(topDist > dist[topNode]){
                continue;
            }

            for(auto nbrPair : adjList[topNode]){
                auto nbrDist = nbrPair.first;
                auto nbrNode = nbrPair.second;
                if(topDist + nbrDist < dist[nbrNode]){
                    auto previousEntry = st.find({ dist[nbrNode],nbrNode });
                    if(previousEntry != st.end()){
                        st.erase({dist[nbrNode],nbrNode });
                    }
                    dist[nbrNode] = topDist +nbrDist;
                    st.insert({dist[nbrNode] , nbrNode});
                }
            }


        }

    }

};

