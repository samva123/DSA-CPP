#include <bits/stdc++.h>
using namespace std;
// next smaller element
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
        }

        return ans;
    }
};



#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;// arr[i] *(nse-pse-1)
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};



// Explanation
// Stack-based approach: This approach uses a single stack to keep track of the indices of the histogram bars.
// Iterate through the heights: For each bar, we calculate the maximum area possible with the bar as the smallest (or limiting) height.
// Calculate width and area: When a bar is popped from the stack, the width of the rectangle is calculated based on the current index and the index of the new top of the stack.
// Update maximum area: The maximum area is updated accordingly.
// This approach maintains the O(n) time complexity and O(n) space complexity but is more concise and easier to understand.

