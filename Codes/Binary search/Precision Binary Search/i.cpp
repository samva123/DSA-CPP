// #include <iostream>
// #include <vector>

// using namespace std;

// int mySqrt(int n)
// {
//     int s = 0, e = n;
//     int ans = 0;
//     while (s <= e)
//     {
//         int mid = (e - s) / 2 + s;

//         // predicate fn
//         if (mid * mid <= n)
//         {
//             ans = mid;
//             s = mid + 1; // go right
//         }
//         else
//             e = mid - 1; // go left
//     }
//     return ans;
// }

// double myPrecisionSqrt(int n)
// {
//     double sqrt = mySqrt(n);
//     int precision = 7;
//     double step = 0.1;
//     for (int i = 0; i < precision; ++i)
//     {
//         double j = sqrt;
//         while (j * j <= n)
//         {
//             sqrt = j;
//             j += step;
//         }
//         step /= 10;
//     }
//     return sqrt;
// }

// int main()
// {
//     int n = 63;
//     // cout << mySqrt(n) << endl;
//     cout << myPrecisionSqrt(n) << endl;
//     return 0;
// }











#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mySqrt(int n) {
    int s = 0, e = n, ans = 0;
    while (s <= e) {
        long long mid = s + (e - s) / 2;  // use long long to avoid overflow
        if (mid * mid <= n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

double myPrecisionSqrt(int n, int precision = 7) {
    double ans = mySqrt(n);
    double factor = 1;

    for (int i = 0; i < precision; ++i) {
        factor /= 10;
        while ((ans + factor) * (ans + factor) <= n) {
            ans += factor;
        }
    }
    return ans;
}

int main() {
    int n = 63;
    cout << fixed << setprecision(10) << myPrecisionSqrt(n) << endl;
    return 0;
}















#include <iostream>
#include <string>
using namespace std;

int mySqrt(int n) {
    int s = 0, e = n, ans = 0;
    while (s <= e) {
        long long mid = s + (e - s) / 2;
        if (mid * mid <= n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

string preciseSqrt(int n, int precision = 7) {
    double ans = mySqrt(n);
    double factor = 1;
    string result = to_string((int)ans) + "."; // integer part

    for (int i = 0; i < precision; ++i) {
        factor /= 10;
        int digit = 0;
        while ((ans + factor) * (ans + factor) <= n) {
            ans += factor;
            digit++;
        }
        result += to_string(digit);
    }
    return result;
}

int main() {
    int n = 63;
    cout << preciseSqrt(n, 7) << endl;
    return 0;
}
