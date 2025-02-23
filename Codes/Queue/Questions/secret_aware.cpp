#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;
        int cur = 0 ;
        int ans = 1;
        queue<pair<int,int>>delayq,forgetq;
        delayq.push({1,1});
        forgetq.push({1,1});

        for(int i = 1 ; i <= n ; ++i){
            if(!forgetq.empty() && forgetq.front().first + forget <= i){
                auto front = forgetq.front();
                forgetq.pop();
                auto no = front.second;
                ans = (ans-no+M)%M;
                cur = (cur-no+M)%M;
                 
            }

                if(!delayq.empty() && delayq.front().first + delay <= i){
                    auto front = delayq.front();
                    delayq.pop();
                    cur = (cur+front.second)%M;
                }

                if(cur > 0){
                    ans = (ans+cur)%M;
                    delayq.push({i , cur});
                    forgetq.push({i , cur});
                }
        }
        return ans;
        
    }
    
    
    
    #include <bits/stdc++.h>
    using namespace std;
    
    class Solution1 {
    public:
        int peopleAwareOfSecret(int n, int delay, int forget) {
            const int M = 1e9 + 7;
            queue<pair<int, int>> q; // Stores (day, new_people)
            int ans = 1; // Initially, one person knows the secret
            q.push({1, 1}); // (day they start sharing, count of people)
    
            for (int i = 1; i <= n; ++i) {
                // Remove people who forget the secret
                while (!q.empty() && q.front().first + forget == i) {
                    ans = (ans - q.front().second + M) % M;
                    q.pop();
                }
    
                // Start sharing after `delay` days
                if (!q.empty() && q.front().first + delay == i) {
                    int new_people = ans; // All who currently know can start sharing
                    q.push({i, new_people});
                    ans = (ans + new_people) % M;
                }
            }
    
            return ans;
        }
    };
    
};