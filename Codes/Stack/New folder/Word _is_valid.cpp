class Solution {
public:
    bool isValid(string s) {

        if(s.size() == 0){
            return true;
        }
        int fnd = s.find("abc");
        if(fnd != string::npos){
            string tleft = s.substr(0, fnd);
            string tright = s.substr(fnd+3 , s.size());
            return isValid(tleft+tright);
        }

        return false;


        
    }
};





class Solution {
public:
    bool isValid(string s) {

       

        if(s[0] != 'a'){
            return false;
        }

        stack<char>st;

        for(char ch : s){
            if(ch == 'a'){
                st.push(ch);

            }
            else if(ch == 'b') {
                if(!st.empty() && st.top() == 'a'){
                    st.push('b');
                }
                else{
                    return false;
                }


            }
            else{
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }


                }
                else{
                    return false;
                }
            }
        }
        return st.empty() ;
        
    }
};













bool isValid(string s) {
    int a_count = 0, b_count = 0;

    for (char ch : s) {
        if (ch == 'a') {
            a_count++;
        } else if (ch == 'b') {
            if (a_count > 0) {
                b_count++;
            } else {
                return false;
            }
        } else {
            if (b_count > 0) {
                b_count--;
                a_count--;
            } else {
                return false;
            }
        }
    }

    return a_count == 0 && b_count == 0;
}




// Explanation
// Use two counters a_count and b_count to keep track of the number of 'a' and 'b' characters.
// Traverse the input string s:
// Increment a_count for each 'a'.
// If a 'b' is encountered and there is an unmatched 'a', increment b_count.
// Otherwise, return false.
// If any other character is encountered, check if there is an unmatched 'b' and 'a' to form a valid sequence. If so, decrement both counters. Otherwise, return false.
// After the loop, check if both a_count and b_count are zero, indicating that all characters have been matched correctly.
// This approach maintains the time complexity of O(n) and reduces the space complexity to O(1).