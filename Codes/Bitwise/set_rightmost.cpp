class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        return n | n+1;
    }
};



#include <iostream>

int main() {
    int n = 12; // Binary: 1100
    n = n & (n - 1); // Clears the rightmost set bit

    std::cout << "After unsetting the rightmost set bit: " << n << std::endl;
    return 0;
}

