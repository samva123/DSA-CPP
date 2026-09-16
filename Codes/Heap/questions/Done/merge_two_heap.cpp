// User function Template for C++
#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    void heapify(vector<int>&v , int i , int n){
        while(true){
            int left = 2*i +1;
            int right = 2*i + 2;
            int swapindex = i;
            if(left < n && v[left] > v[i]){
                swapindex = left;
            }
            if(right < n && v[right] > v[swapindex]){
                swapindex = right;
            }
            if(swapindex == i ){
                break;
            }
            swap(v[i] , v[swapindex]);
            i = swapindex;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>c(a.begin() ,  a.end());
        c.insert(c.end() , b.begin() , b.end());
        
        for(int i = (c.size()/2)-1 ; i>= 0 ; --i){
            heapify(c,i,c.size());
        }
        return c;
        
    }
};
