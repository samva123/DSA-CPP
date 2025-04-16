#include <iostream>
#include <string>
using namespace std;

bool canFormUsing2And6(int nedd, int count2, int count3) {
    for (int i = 0; i <= count2; i++) {  
        for (int j = 0; j <= count3; j++) {  
            if (i * 2 + j * 6 == nedd) {
                return true;
            }
        }
    }
    return false;
}

void processNumber(const string& num) {
    int count2 = 0, count3 = 0, digitSum = 0;

    for (char digit : num) {
        int d = digit - '0';
        if (d == 2) count2++;
        if (d == 3) count3++;
        digitSum += d;
    }

    if (digitSum % 9 == 0) {
        cout << "YES" << endl;
        return;
    }

    bool possible = false;
    int nextMultiple = ((digitSum / 9) + 1) * 9;

    while (nextMultiple <= digitSum + (count2 * 2) + (count3 * 6)) {  
        int nedd = nextMultiple - digitSum;
        if (canFormUsing2And6(nedd, count2, count3)) {
            possible = true;
            break;
        }
        nextMultiple += 9;
    }

    cout << (possible ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string num;
        cin >> num;
        processNumber(num);
    }
    return 0;
}
