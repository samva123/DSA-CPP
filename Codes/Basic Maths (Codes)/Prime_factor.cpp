// https://takeuforward.org/plus/dsa/problems/prime-factorisation-of-a-number
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> primeFactorization(vector<int>& queries) {
    int MAX = *max_element(queries.begin(), queries.end());

    vector<int> spf(MAX + 1);
    for (int i = 1; i <= MAX; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAX; i++) {
        if (spf[i] == i) { // prime
            for (int j = i * i; j <= MAX; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    vector<vector<int>> result;

    for (int x : queries) {
        vector<int> factors;
        while (x > 1) {
            factors.push_back(spf[x]);
            x /= spf[x];
        }
        result.push_back(factors);
    }

    return result;
}
