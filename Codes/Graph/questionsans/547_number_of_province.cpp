#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};










class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int j = 0; j < n; j++) {
                        if (isConnected[node][j] == 1 && !visited[j]) {
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};
