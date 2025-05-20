#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_set<char> seen;
        bool flag = true;
        seen.insert(s[0]);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                if (seen.count(s[i])) {
                    flag = false;
                    break;
                }
            }
            seen.insert(s[i]);
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
