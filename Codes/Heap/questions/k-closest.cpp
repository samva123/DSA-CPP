#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    class mycomp {
    public:
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            int distA = a.first*a.first + a.second*a.second;
            int distB = b.first*b.first + b.second*b.second;
            return distA < distB;   // max-heap (larger distance has higher priority)
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomp> pq;

        for (auto &p : points) {
            pq.push({p[0], p[1]});
            if ((int)pq.size() > k) {
                pq.pop();  // remove farthest point
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans.push_back({top.first, top.second});
        }
        return ans;
    }
};
///////////////////slight better than the first submitted one/////////