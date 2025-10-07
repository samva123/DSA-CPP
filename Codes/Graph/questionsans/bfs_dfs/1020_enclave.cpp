#include<bits/stdc++.h>
using namespace std;

////i wrote the approach using visited but below approach is more 
////optimal as it has O(1) space 


class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = 0;  // mark visited

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        for(int k = 0; k < 4; k++) {
            int newx = i + dx[k];
            int newy = j + dy[k];

            if(newx >= 0 && newy >= 0 && newx < n && newy < m && grid[newx][newy] == 1) {
                dfs(newx, newy, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // flood-fill from boundary lands
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};





















#include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     void bfs(int i, int j, vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         queue<pair<int,int>> q;
//         q.push({i,j});
//         grid[i][j] = 0;  // mark visited

//         int dx[] = {-1, 0, 0, 1};
//         int dy[] = {0, -1, 1, 0};

//         while(!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();

//             for(int k = 0; k < 4; k++) {
//                 int newx = x + dx[k];
//                 int newy = y + dy[k];

//                 if(newx >= 0 && newy >= 0 && newx < n && newy < m && grid[newx][newy] == 1) {
//                     grid[newx][newy] = 0;  // mark visited
//                     q.push({newx, newy});
//                 }
//             }
//         }
//     }

//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         // flood-fill from boundary land cells
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if((i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1) {
//                     bfs(i, j, grid);
//                 }
//             }
//         }

//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == 1) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
