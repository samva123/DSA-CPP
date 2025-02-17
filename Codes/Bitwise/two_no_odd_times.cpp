#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoOddNum(vector<int> Arr, int N) {
        int XOR_all = 0;

        // Step 1: XOR all elements to get XOR of the two odd occurring numbers
        for (int num : Arr) {
            XOR_all ^= num;
        }

        // Step 2: Find the rightmost set bit in XOR_all
        int rightmost_set_bit = XOR_all & -XOR_all;

        int x = 0, y = 0;

        // Step 3: Divide elements into two groups and XOR separately
        for (int num : Arr) {
            if (num & rightmost_set_bit)
                x ^= num;  // Group 1: Bit is set
            else
                y ^= num;  // Group 2: Bit is not set
        }

        // Step 4: Return in decreasing order
        if (x < y) swap(x, y);
        return {x, y};
    }
};

// Driver code for testing
int main() {
    Solution solution;
    vector<int> Arr = {4, 2, 4, 5, 2, 3, 3, 1};
    vector<int> result = solution.twoOddNum(Arr, Arr.size());

    cout << "Odd occurring numbers: " << result[0] << " " << result[1] << endl;
    return 0;
}
