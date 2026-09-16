#include <bits/stdc++.h>
using namespace std;



// return 2 number which appear only once and all other twice
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xr = 0;

        for (int x : nums)
            xr ^= x;

        int mask = xr & (-xr);

        int a = 0;
        int b = 0;

        for (int x : nums) {

            if (x & mask)
                a ^= x;
            else
                b ^= x;
        }

        if (a > b)
            swap(a, b);

        return {a, b};
    }
};


// return number which apper 1 team and all other 3 times(revise it)
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }
};