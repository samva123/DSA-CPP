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