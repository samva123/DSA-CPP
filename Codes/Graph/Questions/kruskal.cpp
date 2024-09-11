//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    static bool mycmp(vector<int>&a , vector<int>&b){
        return a[2] < b[2];
        
    }
	public:
	
	int findparent(vector<int>&parent , int node){
	    if(parent[node] == node){
	        return node ;
	        
	    }
	    return parent[node] =  findparent(parent , parent[node]);
	}
	
	void unionset(int u , int v , vector<int>&parent , vector<int>&rank){
	    u = findparent(parent , u);
	    v = findparent(parent , v);
	    
	    if(rank[u] < rank[v]){
	        parent[u] = v;
	        rank[v]++;
	    }
	    else{
	        parent[v] = u;
	        rank[u]++;
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>parent(V);
        vector<int>rank(V,0);
        
        for(int u = 0 ; u<V ; ++u){
            parent[u] = u;
        }
        
        vector<vector<int>>edges;
        for(int u = 0 ; u<V;++u){
            for(auto edge : adj[u]){
                int v = edge[0];
                int w = edge[1];
                edges.push_back({u,v,w});
            }
        }
        sort(edges.begin() , edges.end() ,mycmp);
        
        int ans = 0;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            u = findparent(parent , u);
            v = findparent(parent , v);
            
            if(u!=v){
                unionset(u,v,parent,rank);
                ans += w;
            }
        }
        
        
        return ans;
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