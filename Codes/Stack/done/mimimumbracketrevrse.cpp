// o(n) && o(n)
int countRev (string s)
{
   if(s.size()&1) return -1;

        int ans = 0;
        stack<char>st;
        for(char ch:s){
            if(ch == '{'){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == '{' ){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
            char a = st.top(); st.pop();
            char b = st.top(); st.pop();
            if(a == b){
                ans += 1;
            
            }
            else{
                ans += 2;
            }
        }
        return ans;
}




// o(n) && o(1)
int countRev (string s)
{
    if(s.size() & 1) return -1;

    int left_brace = 0, right_brace = 0;
    for(char ch : s) {
        if(ch == '{') {
            left_brace++;
        } else {
            if(left_brace > 0) {
                left_brace--;
            } else {
                right_brace++;
            }
        }
    }

    return (left_brace + 1) / 2 + (right_brace + 1) / 2;
}





// Explanation
// If the size of the string is odd, return -1 immediately because it's impossible to balance an odd number of brackets.
// Use two counters left_brace and right_brace to keep track of unmatched left and right braces.
// Traverse the string:
// Increment left_brace for each '{'.
// If a '}' is encountered and there is an unmatched '{', decrement left_brace.
// Otherwise, increment right_brace.
// The number of reversals needed to balance the string is the sum of half the unmatched left braces and half the unmatched right braces, rounded up. This is calculated as (left_brace + 1) / 2 + (right_brace + 1) / 2.
// This approach reduces the space complexity to O(1) while maintaining the time complexity of O(n).