#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, count = 0;
        cin >> n >> m;
        
        vector<string> words(n);  // Store all words first
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

          // Flag to stop counting when a longer string is found
        for (const string &s : words) {
            if (s.length() <= m) {
                count++;
                m -= s.length();
            } else {
                break; // Stop counting but continue iterating
            }
        }

        cout << count << endl;
    }

    return 0;
}
