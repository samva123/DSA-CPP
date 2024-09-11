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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);

        for(int i = 0 ; i<n ;++i) parent[i] = i;

        unordered_map<string , int>mp;
        for(int i =0 ; i< n; i++){
            auto account = accounts[i];
            for(int j = 1;j<account.size() ; ++j){
                string&mail = account[j];
                auto it  = mp.find(mail);
                if(it == mp.end()) mp[mail] = i;
                else unionset(i , it->second,parent,rank);
            }
        }

        unordered_map<int , set<string>>preAns;
        for(auto it : mp){
            int accno = it.second;
            auto mail = it.first;
            accno = findparent(parent , accno);
            preAns[accno].insert(mail);


        }

        vector<vector<string>>ans;
        for(auto it : preAns){
            auto accno = it.first;
            auto st = it.second;
            vector<string>v;
            v.push_back(accounts[accno][0]);
            for(auto mail:st) v.push_back(mail);
            ans.push_back(v);

        }
        return ans;
        

    }
};