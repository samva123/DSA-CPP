//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        
        for(int i = 0 ; i<n;i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        int mightbe = st.top();
        st.pop();
        
        for(int i = 0 ; i<n ; i++){
            if(M[mightbe][i] != 0){
                return -1;
            }
             
        }
        for(int i =0; i<n ;++i){
            if(M[i][mightbe] == 0 && mightbe != i )
            return -1;
             
        }
        return mightbe;
        
        
        
    }
};







class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int a = 0, b = n - 1;
        
        while (a < b) {
            if (M[a][b]) {
                a++;
            } else {
                b--;
            }
        }
        
        int candidate = a;
        
        for (int i = 0; i < n; i++) {
            if (i != candidate && (M[candidate][i] || !M[i][candidate])) {
                return -1;
            }
        }
        
        return candidate; 
    }
};




// Explanation
// Use two pointers a and b to represent the potential celebrity candidates.
// Traverse the matrix:
// If M[a][b] is true, then a cannot be a celebrity, so increment a.
// Otherwise, b cannot be a celebrity, so decrement b.
// After the loop, a will be the only candidate left.
// Verify the candidate by checking:
// The candidate should not know anyone else.
// Everyone else should know the candidate.
// If the candidate passes the verification, return the candidate's index; otherwise, return -1.
// This approach maintains the time complexity of O(n) but reduces the space complexity to O(1).