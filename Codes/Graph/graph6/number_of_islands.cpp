#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1' && !vis[{i, j}])
            return true;
        return false;
    }
w
    void bfs(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[{i, j}] = true;
        while (!q.empty())
        {
            auto frontNode = q.front();
            q.pop();
            int tempX = frontNode.first;
            int tempY = frontNode.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++)
            {
                int newX = tempX + dx[k];
                int newY = tempY + dy[k];
                if (isSafe(newX, newY, grid, vis))
                {
                    q.push({newX, newY});
                    vis[{newX, newY}] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        map<pair<int, int>, bool> vis;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[{i, j}] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};









/////////////////////dfs//////////////////////

class Solution {
    public:
        void dfs(vector<vector<char>>& grid , int i , int j){
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0' || grid[i][j] == 'x'){
                return ;
            }
            grid[i][j] = 'x';
            
    
            dfs(grid , i-1 , j); dfs(grid , i , j-1) ; dfs(grid , i+1 ,j) ; dfs(grid , i , j+1);
            
    
        }
        int numIslands(vector<vector<char>>& grid) {
            auto m = grid.size();
            auto n = grid[0].size();
    
            int ans = 0;
    
            for(int i = 0 ; i<m ; i++){
                for(int j = 0 ; j<n ; j++){
                    if(grid[i][j] != 'x' && grid[i][j] != '0' ){
                        dfs(grid , i ,j);
                        ans++;
                    }
                    
                }
            }
            return ans;
            
        }
    };