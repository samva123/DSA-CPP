#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;  // Sort by value descending
    }
};

int main() {
    map<int, int> freq = {{1, 5}, {2, 3}, {3, 8}};

    set<pair<int, int>, Compare> sortedSet(freq.begin(), freq.end());

    for (auto& p : sortedSet) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
