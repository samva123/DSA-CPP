class Solution {


public:

 vector<int> nextSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            if (st.top() == -1)
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    // prev Smaller
    vector<int> prevSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n=heights.size();
        if(n==1)return heights[0];
        vector<int>  leftToRight=prevSmaller(heights,n);
        vector<int> rightToLeft=nextSmaller(heights,n);
        // rev krdo
        // reverse(rightToLeft.begin(),rightToLeft.end());
        vector<int>area(leftToRight.size());
        for(int i=0;i<leftToRight.size();i++){
            int width=rightToLeft[i]-leftToRight[i]-1;
            int length=heights[i];      
            area[i]=width*length;
        }
        int maxi=INT_MIN;
        for(int i=0;i<area.size();i++){
            maxi=max(maxi,area[i]);
        }
        return maxi;
       
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0 ; i < n  ; ++i){
            vector<int>t;
            for(int j = 0 ; j < m  ; ++j){
                t.push_back(matrix[i][j] - '0');

            }
            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);

        for(int i = 1 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(v[i][j] ){
                    v[i][j] += v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area , largestRectangleArea(v[i]));
        }
        return area;


        
    }
};





class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); // Add a sentinel value to handle remaining elements in the stack
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};




// Explanation of the Code
// largestRectangleArea:
// Use a stack to keep track of the indices of the heights.
// Traverse the heights and calculate the maximum area for each height.
// Add a sentinel value to handle remaining elements in the stack.
// maximalRectangle:
// Convert the input matrix from characters to integers.
// Initialize the heights vector to store the heights of the histogram for each row.
// For each row in the matrix:
// Update the heights vector by adding the values from the previous row if the current value is '1'.
// Call the largestRectangleArea function to calculate the maximum area for the updated heights vector.
// Update the maxArea variable with the maximum area found.
// Return:
// Return the maxArea variable containing the maximum area of the rectangle.
// This approach ensures that each element is processed exactly once, maintaining the overall time complexity of O(n * m) and space complexity of O(m).