#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxHeap;

        if(a > 0) maxHeap.push({a,'a'});
        if(b > 0) maxHeap.push({b,'b'});
        if(c > 0) maxHeap.push({c,'c'});

        string ans = "";

        while(maxHeap.size() > 1) {

            auto first = maxHeap.top(); 
            maxHeap.pop();
            auto second = maxHeap.top(); 
            maxHeap.pop();

            int fcount = first.first;
            char fchar = first.second;

            int scount = second.first;
            char schar = second.second;

            if(fcount >= 2){
                ans.push_back(fchar);
                ans.push_back(fchar);
                fcount -= 2;
            } else {
                ans.push_back(fchar);
                fcount--;
            }

            if(scount >= 2 && scount >= fcount){
                ans.push_back(schar);
                ans.push_back(schar);
                scount -= 2;
            } else {
                ans.push_back(schar);
                scount--;
            }

            if(fcount > 0) maxHeap.push({fcount, fchar});
            if(scount > 0) maxHeap.push({scount, schar});
        }

        if(maxHeap.size()==1){
            auto last = maxHeap.top();
            int cnt = last.first;
            char ch = last.second;

            if(cnt >= 2){
                ans.push_back(ch);
                ans.push_back(ch);
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
