#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        const int mod = 100000;
        vector<int> ans(100000, -1);
        ans[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            if (front == end) return ans[end];
            for (auto it : arr) {
                int newnode = (front * it) % mod;
                if (ans[newnode] == -1) {
                    ans[newnode] = ans[front] + 1;
                    q.push(newnode);
                }
            }
        }
        return -1;
    }
};












////////////////above one is the best but below is striver approach //////////


class Solution
{
public:
    int minimumMultiplications(vector<int> &arr,
                               int start, int end)
    {
        queue<pair<int, int>> q;
        q.push({start, 0});

        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;

        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                int num = (it * node) % mod;

                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;

                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};

