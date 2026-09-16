//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int getminvalue(vector<int>&key , vector<int>&mst){
	    int temp = INT_MAX;
	    int index = -1;
	    for(int i = 0;i<key.size();++i ){
	        if(key[i] < temp && mst[i] == false){
	            temp = key[i];
	            index = i;
	        }
	        
	    }
	    return index;
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>key(V,INT_MAX);
        vector<int>mst(V,false);
        vector<int>parent(V,-1);
        
        key[0] = 0;
        
        while(true){
            int u = getminvalue(key ,mst);
            
            if(u == -1) break;
            
            
            
            mst[u] = true;
            
            for(auto edge : adj[u]){
                int v = edge[0];
                int w = edge[1];
                if(mst[v] == false && w < key[v]){
                    key[v] = w;
                    parent[v] = u ;
                }
            }
        }
        int sum = 0;
        for(int u = 0 ; u < parent.size(); ++u){
            if(parent[u] == -1) continue;
            
           for(auto edge : adj[u]){
               int v = edge
               
               [0];
               int w = edge[1];
               if(v == parent[u]){
                   sum += w ;
               }
               
           } 
            
        }
        return sum;
       
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends











#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<pair<int, int>>> &adj) {

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> vis(V, 0);

        pq.push({0, 0}); // {weight, node}

        int sum = 0;

        while (!pq.empty()) {

            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = 1;
            sum += wt;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (!vis[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }

        return sum;
    }
};

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 2, 2}
    };

    vector<vector<pair<int, int>>> adj(V);

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    Solution obj;

    cout << "Sum of MST = " << obj.spanningTree(V, adj);

    return 0;
}