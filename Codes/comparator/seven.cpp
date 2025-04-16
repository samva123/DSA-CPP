#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    map<int, int> freq = {{1, 5}, {2, 3}, {3, 8}};

    multimap<int, int, greater<int>> sortedMap;
    for (auto& p : freq) {
        sortedMap.insert({p.second, p.first}); // Flip key-value pair
    }

    for (auto& p : sortedMap) {
        cout << p.second << " -> " << p.first << endl;
    }

    return 0;
}
