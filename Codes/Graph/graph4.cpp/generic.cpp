#include <iostream>
#include<set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
#include<climits>


using namespace std;

template<typename T>

class Graph{
    public:

    unordered_map<T , list<pair<T , int >>>adjList;
    void addEdge(T u , T v , int wt , bool direction){
        if(direction == 0){
            adjList[u].push_back({v , wt});
            adjList[v].push_back({u , wt});
        }else{
            adjList[u].push_back({v , wt});
        }

        cout << endl;
        printadj();
    }

    void printadj(){
        for(auto i : adjList){
            cout << i.first << " : "  << " { ";
            for(auto nbr : i.second){
                cout << "{" << nbr.first << "," << nbr.second << "}" << " ";
            }
            cout << " } ";
            cout << endl;
        }
    }


    void toposortdfs(T src , unordered_map<T , bool>&vis , stack<T>&topo){
        vis[src] = true;

        for(auto nbr : adjList[src]){
            auto nbrData  = nbr.first;
            if(!vis[nbrData]){
                toposortdfs(nbrData , vis , topo);
            }
        }

        topo.push(src);
    }

    void shortpathdfs(T src , unordered_map<T , int>&dist , stack<T>&topo){

        T ele  = topo.top();
        topo.pop();
        dist[src] = 0 ;


        for(auto nbr : adjList[src]){
            auto 

        }








    }



};


int main() {
    Graph<char> g;

    g.addEdge('a', 'b', 2, 1);
    g.addEdge('a', 'c', 3, 1);
    g.addEdge('b', 'd', 4, 1);
    g.addEdge('c', 'd', 1, 1);
    g.addEdge('d', 'e', 2, 1);
    g.addEdge('c', 'f', 5, 1);
    g.addEdge('e', 'g', 3, 1);
    g.addEdge('f', 'g', 2, 1);


    stack<char>st;
    unordered_map<char , bool>vis;
    for(auto node : g.adjList){
        if(!vis[node.first]){
            g.toposortdfs(node.first , vis , st );
        }
    }
    


    while(!st.empty()){
        auto ele  = st.top();
        st.pop();
        cout << ele << " ";

    }

    cout << endl <<  endl;

    unordered_map<char , int>dist;
    for(auto node : g.adjList){
        dist[node.first] = INT_MAX;

    }
    g.shortpathdfs('a' , dist , st);

    return 0;
}
