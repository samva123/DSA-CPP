#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of bit flips
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits and count set bits
        return __builtin_popcount(start ^ goal);  
    }
};


// Use a built-in function for set bits count (__builtin_popcount(n)) in GCC/Clang or _popcnt(n) in MSVC.














class Solution {
public:
    // Function to find the minimum number of bit flips
    int minBitFlips(const int start, const int goal) const {
        // XOR the numbers to find differing bits
        unsigned int diff = start ^ goal;
        
        // Count the number of set bits in the XOR result (which indicates differing bits)
        int count = 0;
        while (diff != 0) {
            count++;
            diff &= (diff - 1);  // This operation removes the rightmost set bit
        }
        return count;
    }
};