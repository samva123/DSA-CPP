///////////////////first is map approach////////////








// this is second approach////////////

#include <iostream>
#include <vector>
using namespace std;

int findUniqueNumber(vector<int>& nums) {
    int ans = 0;

    // Iterate over each bit position (0 to 31 for 32-bit integers)
    for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
        int count = 0;

        // Count how many numbers have this bit set
        for (int num : nums) {
            if (num & (1 << bitIndex)) {
                count++;
            }
        }

        // If count is not a multiple of 3, this bit belongs to the unique number
        if (count % 3 == 1) {
            ans |= (1 << bitIndex);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 3, 3, 3};  // Only '2' appears once
    cout << "Unique Number: " << findUniqueNumber(nums) << endl;
    return 0;
}






////////this is third approach/////////////


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findUniqueNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // Step 1: Sort the array

    int n = nums.size();
    for (int i = 1; i < n; i += 3) {  // Step 2: Move in steps of 3
        if (nums[i] != nums[i - 1]) { // Step 3: Check if previous element is different
            return nums[i - 1];  // Found the unique number
        }
    }

    return nums[n - 1];  // Edge case: If the unique number is the last element
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 3, 3, 3};  // Unique number is '2'
    cout << "Unique Number: " << findUniqueNumber(nums) << endl;
    return 0;
}











////////////////////last approach///////////
#include <iostream>
#include <vector>
using namespace std;

int findUniqueNumber(vector<int>& nums) {
    int ones = 0, twos = 0;

    for (int num : nums) {
        ones = (ones ^ num) & ~twos;  // Add to 'ones' if not in 'twos'
        twos = (twos ^ num) & ~ones;  // Add to 'twos' if in 'ones'
    }

    return ones;  // 'ones' contains the unique number
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 3, 3, 3};  // Unique number is '2'
    cout << "Unique Number: " << findUniqueNumber(nums) << endl;
    return 0;
}
