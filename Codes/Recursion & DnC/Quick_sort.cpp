#include<bits/stdc++.h>
using namespace std;


void quicksort(vector<int>&arr , int start , int end){
    if(start >= end){
        return ;
    }

    int pivot  = end;
    int i = start -1;
    int j = start;

    while(j < pivot){
        if(arr[j] < arr[pivot]){
            ++i;
            swap(arr[i] , arr[j]);
        }
        ++j;
    }
    ++i;
    swap(arr[i] , arr[pivot]);
    quicksort(arr , start , i-1);
    quicksort(arr , i+1 , end);
    
}

int main(){
    vector<int>demo = {6,5,4,3,2,1};

    quicksort(demo, 0 , 5);

    for(auto x : demo){
        cout << x << " ";
    }
    return 0;

}