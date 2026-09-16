#include <iostream>
#include <cstring>
using namespace std;

// You implement this
char* longestCommonPrefix(char** arr, int n) {
    // TODO
}

int main() {
    int n;
    cin >> n;

    char** arr = new char*[n];

    for(int i = 0; i < n; i++) {
        char temp[100];
        cin >> temp;
        arr[i] = new char[strlen(temp) + 1];
        strcpy(arr[i], temp);
    }

    char* ans = longestCommonPrefix(arr, n);
    cout << ans << endl;

    // cleanup
    delete[] ans;
    for(int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;

    return 0;
}
