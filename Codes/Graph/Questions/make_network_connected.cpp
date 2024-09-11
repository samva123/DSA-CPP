class Solution {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0 ; i< n ;++i){
            parent[i] = i ;
        }

        int extraedge = 0;
        for(auto connection:connections){
            int u = connection[0];
            int v =  connection[1];


            u = findparent(parent , u);
            v = findparent(parent , v);

            if(u!=v){
                unionset(u ,v , parent,rank);
            }
            else
                ++extraedge;
        }

        int nocc = 0;
        for(int i = 0 ; i<n;i++){
            if(parent[i] == i) nocc++;
        }
        int ans = nocc-1;
        return extraedge >= ans ? ans : -1;
        
    }
};

//1319