#include <bits/stdc++.h>
using namespace std;

// Function to find LOWER BOUND
// Returns index of the first element >= target
int lowerBound(vector<int>& arr, int target) {
    int s = 0, e = arr.size();
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] < target)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

// Function to find UPPER BOUND
// Returns index of the first element > target
int upperBound(vector<int>& arr, int target) {
    int s = 0, e = arr.size();
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= target)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 5, 7, 9};

    int target = 4;

    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);

    cout << "Lower Bound index: " << lb << endl;
    cout << "Upper Bound index: " << ub << endl;

    if (lb < arr.size()) cout << "Lower Bound value: " << arr[lb] << endl;
    if (ub < arr.size()) cout << "Upper Bound value: " << arr[ub] << endl;

    return 0;
}
// 💡 Quick Recap:
// Function	Condition	Meaning
// lower_bound	>= target	First element not less than target
// upper_bound	> target	First element greater than target