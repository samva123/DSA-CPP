#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<set>
#include<queue>

using namespace std;


template <typename T>
class Graph{
    public:
    unordered_map<T , list<pair<T , int>>>adjList;

    void addEdge(T u , T v , int wt ,  int direction){
        if(direction == 0){
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u ,wt});
        }else{
            adjList[u].push_back({v,wt});
        }

        printadj();
    }

    void printadj(){
        for(auto i : adjList){
            cout << i.first << " -> " << " { ";
            for(auto p : i.second){
                cout << " { " << p.first << "," << p.second << " } ";
            }
            cout << " } ";
            cout << endl;
        }
    }

    void bfs(T src , unordered_map<T,bool>&vis){

        queue<T>q;
        
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            T fnode= q.front();
            cout << fnode << " ";
            q.pop();

            for(auto nbr : adjList[fnode]){
                T nbrData  = nbr.first;
                if(!vis[nbrData]){
                    vis[nbrData] = true;
                    q.push(nbrData);
                }
            }
        }
    }

    void dfs(T src , unordered_map<T , bool>&vis){
        vis[src] = true;
        cout << src << " ";

        for(auto nbr : adjList[src]){
            T nbrData  = nbr.first;
            if(!vis[nbrData]){
                dfs(nbrData , vis); 
            }
        }

    }


    


};

int main(){

    Graph<int>g;

    g.addEdge(1,2,2,0);
    g.addEdge(2,3,2,0);
    g.addEdge(3,4,2,0);
    g.addEdge(4,2,2,0);

    unordered_map<int , bool>vis;

    g.bfs(1 , vis);

    vis.clear();
    cout << endl;

    g.dfs(1 , vis);

}
