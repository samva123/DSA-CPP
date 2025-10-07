#include <bits/stdc++.h>
using namespace std;


///////////////////////////////////////bfs//////////

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

//         vector<pair<int,int>> directions = {
//             {-1,-1},{-1,0},{-1,1},
//             {0,-1},        {0,1},
//             {1,-1},{1,0},{1,1}
//         };

//         queue<pair<int,int>> q;
//         q.push({0,0});
//         grid[0][0] = 1; // distance from start

//         while (!q.empty()) {
//             auto [x,y] = q.front();
//             q.pop();
//             int dist = grid[x][y];

//             if (x == n-1 && y == n-1) return dist;

//             for (auto [dx,dy] : directions) {
//                 int nx = x + dx, ny = y + dy;
//                 if (nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0) {
//                     grid[nx][ny] = dist + 1;
//                     q.push({nx,ny});
//                 }
//             }
//         }
//         return -1;
//     }
// };














//////////////////////bidirectional bfs///////////

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

//         vector<pair<int,int>> directions = {
//             {-1,-1},{-1,0},{-1,1},
//             {0,-1},        {0,1},
//             {1,-1},{1,0},{1,1}
//         };

//         // two queues for bidirectional BFS
//         queue<pair<int,int>> q1, q2;
//         vector<vector<int>> dist1(n, vector<int>(n, -1));
//         vector<vector<int>> dist2(n, vector<int>(n, -1));

//         // start from both ends
//         q1.push({0,0}); 
//         dist1[0][0] = 1;

//         q2.push({n-1,n-1}); 
//         dist2[n-1][n-1] = 1;

//         while (!q1.empty() && !q2.empty()) {
//             // expand from the smaller frontier
//             int ans = expand(grid, q1, dist1, dist2, directions, n);
//             if (ans != -1) return ans;

//             ans = expand(grid, q2, dist2, dist1, directions, n);
//             if (ans != -1) return ans;
//         }
//         return -1;
//     }

//     int expand(vector<vector<int>>& grid, queue<pair<int,int>>& q,
//                vector<vector<int>>& distThis,
//                vector<vector<int>>& distOther,
//                vector<pair<int,int>>& directions, int n) 
//     {
//         int size = q.size();
//         while (size--) {
//             auto [x,y] = q.front();
//             q.pop();

//             for (auto [dx,dy] : directions) {
//                 int nx = x + dx, ny = y + dy;
//                 if (nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && distThis[nx][ny]==-1) {
//                     distThis[nx][ny] = distThis[x][y] + 1;
//                     q.push({nx,ny});

//                     // if the other search already visited this cell
//                     if (distOther[nx][ny] != -1) {
//                         return distThis[nx][ny] + distOther[nx][ny] - 1;
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };
