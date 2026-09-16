#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0;      // read pointer
        int index = 0;  // write pointer

        while (i < n) {
            char curr = chars[i];
            int count = 0;

            while (i < n && chars[i] == curr) {
                count++;
                i++;
            }

            chars[index++] = curr;

            if (count > 1) {
                string freq = to_string(count);
                for (char c : freq) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};

