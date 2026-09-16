#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10; // total songs
    vector<int> songs;

    for (int i = 1; i <= n; i++) {
        songs.push_back(i);
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(songs.begin(), songs.end(), g);

    for (int i = 0; i < n; i++) {
        cout << "Playing song: " << songs[i] << endl;
    }
}
