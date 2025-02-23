#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {

        queue<int>q;

        for(int i = 1 ; i <= n ; i++) q.push(i);

        while(q.size() != 1){
            for(int i = 0 ; i<k ; i++){
                if(i == k-1) q.pop();
                else{
                    int tempNum = q.front();
                    q.pop();
                    q.push(tempNum);
                }
            }
        }
        return q.front();
        
    }
};




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Base case: If one person is left, they are at index 0
        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i; // Update position using Josephus formula
        }
        return winner + 1; // Convert zero-based index to 1-based index
    }
};

int main() {
    Solution sol;
    cout << sol.findTheWinner(5, 2) << endl;  // Output: 3
    cout << sol.findTheWinner(6, 5) << endl;  // Output: 1
    return 0;
}
