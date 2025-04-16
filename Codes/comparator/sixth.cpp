#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    // Step 1: Create a frequency map
    map<int, int> freq = {{1, 5}, {2, 3}, {3, 8}, {4, 1}, {5, 6}};

    // Step 2: Define a min-heap based on frequency
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;  // Lower frequency has lower priority
    };

    // Step 3: Declare the priority queue (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    // Step 4: Insert all elements from the map into the priority queue
    for (auto p : freq) {
        pq.push(p);
    }

    // Step 5: Print the priority queue's order (highest frequency first)
    cout << "Priority Queue (sorted by frequency, descending order):\n";
    while (!pq.empty()) {
        cout << pq.top().first << " -> " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
