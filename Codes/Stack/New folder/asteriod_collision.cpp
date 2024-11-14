class Solution {
public:
    //three cases 
    //+ve first => push
    // Top +ve ans ast -ve => collision
    // top -ve and ast -ve => push

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast:asteroids){
            bool destroy = false;
            if(ast > 0){
                st.push(ast);
            }
            else{
                if( st.empty() || st.top() < 0 ){
                    st.push(ast);

                }
                else {
                    while(!st.empty() && st.top() >0){
                        if(abs(ast) == st.top() ){
                            destroy = true;
                            st.pop();
                            break;
                        }
                        else if(abs(ast) > st.top()){
                            st.pop();
                            
                        }
                        else{
                            destroy = true;
                            break; 

                        }
                    }
                    if(!destroy){
                        st.push(ast);
                    }

                }
            }
        }
        vector<int>ans(st.size());
        for(int i = st.size()-1 ; i>=0 ;i--){
            ans[i] = st.top();
            st.pop(); 

        }
        return ans;
        
    }
};



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int ast : asteroids) {
            bool destroyed = false;
            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (st.top() < -ast) {
                    st.pop();
                    continue;
                } else if (st.top() == -ast) {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                st.push(ast);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};

// Explanation
// Use a stack to keep track of the asteroids.
// Traverse the input vector asteroids:
// If the current asteroid ast is positive, push it onto the stack.
// If the current asteroid ast is negative, check for collisions with the top of the stack:
// If the top of the stack is smaller in magnitude, pop it and continue checking.
// If the top of the stack is equal in magnitude, pop it and mark the current asteroid as destroyed.
// If the top of the stack is larger in magnitude, mark the current asteroid as destroyed.
// If the current asteroid is not destroyed, push it onto the stack.
// After processing all asteroids, transfer the remaining asteroids from the stack to the result vector in reverse order.
// This approach maintains the time complexity of O(n) and space complexity of O(n), but it simplifies the code by making the stack operations and collision logic more straightforward.