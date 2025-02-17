#include <iostream>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {
        // Swap using addition and subtraction
        a = a + b;  // a becomes the sum of a and b
        b = a - b;  // b becomes the original value of a
        a = a - b;  // a becomes the original value of b
    }
};

int main() {
    Solution solution;
    int a = 13, b = 9;
    solution.swap(a, b);
    cout << a << " " << b << endl;  // Output: 9 13
    return 0;
}


#include <iostream>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b) {
        // Swap using XOR operation
        a = a ^ b;  // Step 1: a becomes the XOR of a and b
        b = a ^ b;  // Step 2: b becomes the original value of a
        a = a ^ b;  // Step 3: a becomes the original value of b
    }
};

int main() {
    Solution solution;
    int a = 13, b = 9;
    solution.swap(a, b);
    cout << a << " " << b << endl;  // Output: 9 13
    return 0;
}
