#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    auto cmp = [](int a, int b) { return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    pq.push(3);
    pq.push(1);
    pq.push(5);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}





// struct Compare {
//     bool operator()(int a, int b) {
//         return a > b;  // Min-heap: smaller value has higher priority
//     }
// };

// priority_queue<int, vector<int>, Compare> pq;
