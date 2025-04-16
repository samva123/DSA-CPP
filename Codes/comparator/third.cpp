#include <iostream>
#include <set>

using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // Reverse order (largest first)
    }
};

int main() {
    set<int, Compare> s = {5, 2, 8, 1};

    for (int num : s) {
        cout << num << " ";
    }

    return 0;
}
