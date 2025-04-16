#include <iostream>
#include <map>

using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // Reverse order
    }
};

int main() {
    map<int, string, Compare> myMap;
    myMap[1] = "One";
    myMap[3] = "Three";
    myMap[2] = "Two";

    for (auto p : myMap) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
