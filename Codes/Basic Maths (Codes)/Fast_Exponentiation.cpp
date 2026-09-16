#include <iostream>
using namespace std;
#define M 1000000007

int fastExponentiation(int x, int n)
{
    long long int ans = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            // n is odd.
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
        n >>= 1;
    }
    return ans % M;
}

int slowExponentiation(int a, int b)
{
    int ans = 1;
    while (b--)
    {
        ans *= a;
    }
    return ans;
}

int main()
{
    int a = 5;
    int b = 4;

    cout << slowExponentiation(a, b) << endl;
    cout << fastExponentiation(a, b) << endl;
    return 0;
}



// Now map this identity to the code
// Case 1️⃣: n is even

// We do:

// x = x * x;   // x becomes x²
// n = n / 2;   // exponent halves


// So:

// xⁿ → (x²)^(n/2)


// Nothing is lost.

// Case 2️⃣: n is odd

// We do:

// ans = ans * x; // take one x out
// x = x * x;
// n = n / 2;


// So:

// xⁿ → x × (x²)^((n−1)/2)