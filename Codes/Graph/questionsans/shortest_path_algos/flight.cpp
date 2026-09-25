#include <bits/stdc++.h>
using namespace std;

/// ////////////////best we found/////////
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // DIJAKTRAS WITH A BOUND 
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            adj[u].push_back({v,cost});

        }
        vector<int>cost(n,1e9);
        cost[src]=0;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{src,0}});
        // {cost,{node,stop}}
        while(!pq.empty()){
            auto curr=pq.front();
            pq.pop();
            int curr_cost=curr.first;
            int curr_node=curr.second.first;
            int stop=curr.second.second;
            
            //if(curr_cost > cost[curr_node]) continue;
            //we can not use this because it might throw a useful state like{150 , 1}
            for(auto it:adj[curr_node]){
                int next_node=it.first;
                int next_cost=it.second;
                if(stop > k){
                continue;
                }
                
                if(cost[next_node]>curr_cost+next_cost && stop<=k){
                    cost[next_node]=curr_cost+next_cost;
                    pq.push({cost[next_node],{next_node,stop+1}});
                }
            }
        }
        if(cost[dst]==1e9){
            return -1;
        }
        else{
            return cost[dst];
        }
    }
};



////////////////gpt/////////////////
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int price = f[2];

            adj[u].push_back({v, price});
        }

        // {cost, node, stops}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, src, 0});

        // dist[node][stops] = minimum cost to reach node
        // using exactly 'stops' flights
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int stops = curr[2];

            // Since priority_queue is sorted by cost,
            // the first time we reach dst, it is the cheapest valid route.
            if (node == dst) {
                return cost;
            }

            // We can use at most k stops,
            // which means at most k+1 flights.
            if (stops == k + 1) {
                continue;
            }

            for (auto &nbr : adj[node]) {

                int nxt = nbr.first;
                int price = nbr.second;

                int newCost = cost + price;
                int newStops = stops + 1;

                if (newCost < dist[nxt][newStops]) {

                    dist[nxt][newStops] = newCost;

                    pq.push({
                        newCost,
                        nxt,
                        newStops
                    });
                }
            }
        }

        return -1;
    }
};




//old one//////////
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, 
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        vector<int> dist(n, INT_MAX);
        vector<int> stopsUsed(n, INT_MAX);
        dist[src] = 0;
        stopsUsed[src] = 0;

        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();

            int cost = v[0];
            int node = v[1];
            int stops = v[2];

            if (cost > dist[node] && stops >= stopsUsed[node]) 
                continue;


            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto &nbr : adj[node]) {
                int nxt = nbr.first;
                int price = nbr.second;

                int newCost = cost + price;

                // we push only if cost is improved or stops are improved
                if (newCost < dist[nxt] || stops + 1 < stopsUsed[nxt]) {
                    dist[nxt] = newCost;
                    stopsUsed[nxt] = stops + 1;
                    pq.push({newCost, nxt, stops + 1});
                }
            }
        }

        return -1;
    }
};