// Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
// Returned triplet should also be internally sorted i.e. i<j<k.

// Examples:

// Input: arr[] = [0, -1, 2, -3, 1]
// Output: [[0, 1, 4], [2, 3, 4]]
// Explanation: Triplets with sum 0 are:
// arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
// arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>& arr) {
    vector<vector<int>> result;
    int n = arr.size();
    vector<pair<int, int>> indexedArr;

    // Store the original indices along with the values
    for (int i = 0; i < n; ++i) {
        indexedArr.push_back({arr[i], i});
    }

    // Sort the array based on values
    sort(indexedArr.begin(), indexedArr.end());

    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicate elements
        if (i > 0 && indexedArr[i].first == indexedArr[i - 1].first) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = indexedArr[i].first + indexedArr[left].first + indexedArr[right].first;
            if (sum == 0) {
                vector<int> triplet = {indexedArr[i].second, indexedArr[left].second, indexedArr[right].second};
                sort(triplet.begin(), triplet.end()); // Ensure the triplet is sorted by indices
                result.push_back(triplet);
                // Skip duplicate elements
                while (left < right && indexedArr[left].first == indexedArr[left + 1].first) ++left;
                while (left < right && indexedArr[right].first == indexedArr[right - 1].first) --right;
                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = findTriplets(arr);

    for (const auto& triplet : triplets) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
}