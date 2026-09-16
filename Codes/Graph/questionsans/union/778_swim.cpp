#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>visit(n,vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});
        int ans = 0;
        vector<int>dirx{1,-1,0,0};
        vector<int>diry{0,0,1,-1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int height = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == n-1 && y == n-1)
                return height;
            pq.pop();

            for(int i=0;i<4;i++)
            {
                int newx = x + dirx[i];
                int newy = y + diry[i];

                if(newx < 0 || newx >= n || newy <0 || newy >= n || visit[newx][newy])
                continue;
                visit[newx][newy] = true;
                pq.push({max(height,grid[newx][newy]), {newx,newy}});
            }
        }

        return ans;
    }
};





class Solution {
public:
    int n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int x, int y, int t, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (x < 0 || x >= n || y < 0 || y >= n) return false;
        if (vis[x][y] || grid[x][y] > t) return false;
        if (x == n-1 && y == n-1) return true;

        vis[x][y] = true;

        for (auto &d : dirs) {
            if (dfs(x + d[0], y + d[1], t, grid, vis))
                return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int low = grid[0][0], high = n*n - 1;
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if (dfs(0, 0, mid, grid, vis)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
