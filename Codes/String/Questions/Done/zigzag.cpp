#include <bits/stdc++.h>
using namespace std;





string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> rows(numRows);
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;

        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;

        curRow += goingDown ? 1 : -1;
    }

    string ans;
    for (auto &row : rows) ans += row;
    return ans;
}

// this can not be optimised and has O(n) time complexity and O(n) space complexity






class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ans;
        int n = s.size();
        int cycle = 2 * (numRows - 1);

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += cycle) {
                ans += s[j];

                int diag = j + cycle - 2 * i;
                if (i != 0 && i != numRows - 1 && diag < n)
                    ans += s[diag];
            }
        }
        return ans;
    }
};