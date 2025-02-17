class Solution {
public:
    // Helper function to compute XOR of all numbers from 0 to x
    int xorUpTo(int x) {
        if (x % 4 == 0) return x;
        if (x % 4 == 1) return 1;
        if (x % 4 == 2) return x + 1;
        return 0;
    }

    // Main function to compute XOR from L to R
    int findXOR(int l, int r) {
        return xorUpTo(r) ^ xorUpTo(l - 1);
    }
};
