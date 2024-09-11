void djikstra(int src){
    vector<int> dist(V, INT_MAX);
    set<pair<int , int>>st;
    dist[src] = 0;
    st.insert({0,src});

    while(!st.empty()){
        auto top = *st.begin();
        st.erase(st.begin());
        int nodedist = top.first;
        int node = top.second;

        for(auto nbr : adjlist[node]){
            int currdist = nodedist + nbr.second;
            if(currdist < dist[nbr.first]){
                auto it = st.find({dist[nbr.first] , nbr.first});
                if(iy != st.end())
                    st.erase(it);
                dist[nbr.first] = currdist;
                st.insert({dist[nbr.first], nbr.first});
            }
        }
    }
}