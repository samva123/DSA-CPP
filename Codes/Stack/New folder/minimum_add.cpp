class Solution {
public:
    int minAddToMakeValid(string s) {
        // int ans = 0;
        stack<int>st;
        for(auto ch:s){
            if(ch == '('){
                st.push(ch);}
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    continue;
                }
                st.push(ch);
            }



        }
        return st.size();

        
        
        
    }
};



class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftCount = 0, rightCount = 0;
        for (char ch : s) {
            if (ch == '(') {
                leftCount++;
            } else {
                if (leftCount > 0) {
                    leftCount--;
                } else {
                    rightCount++;
                }
            }
        }
        return leftCount + rightCount;
    }
};



// Explanation
// Use two counters leftCount and rightCount to keep track of the number of unmatched left and right parentheses.
// Traverse the input string s:
// Increment leftCount for each '('.
// If a ')' is encountered and there is an unmatched '(', decrement leftCount.
// Otherwise, increment rightCount.
// The total number of additions needed to make the string valid is the sum of leftCount and rightCount.
// This approach maintains the time complexity of O(n) but reduces the space complexity to O(1), making it more space-efficient.