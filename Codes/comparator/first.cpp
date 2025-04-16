#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> v = {{1, 3}, {2, 1}, {3, 2}};

    // Sort based on second value (ascending order)
    // Lambda Function(One-time use)
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;  // Lower frequency has lower priority
    };
    // sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    //     return a.second < b.second;
    // });
    sort(v.begin() , v.end() , cmp);

    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}


/// using a struct 

// struct CustomCompare {
//     bool operator()(pair<int, int> a, pair<int, int> b) {
//         return a.second > b.second;  // Descending order by second value
//     }
// };

// int main() {
//     vector<pair<int, int>> v = {{1, 3}, {2, 1}, {3, 2}};
//     sort(v.begin(), v.end(), CustomCompare());

//     for (auto p : v) {
//         cout << p.first << " " << p.second << endl;
//     }

//     return 0;
// }

