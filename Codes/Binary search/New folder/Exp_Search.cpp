#include<iostream>
using namespace std;

int expSearch(int a[], int n, int x){
    if(a[0] == x){
        return 0;
    }
    int i = 1;
    while(i < n && a[i] <= x){
        i = i*2;
    }
    int low = i/2;
    int high = min(i,n-1);
    while(low <= high){
        int mid = low + (high - low)/2;
        if(a[mid] == x){
            return mid;
        }else if(a[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(a[0]);
    int x= 13;
    int ans  = expSearch(a,n,x);
    cout << ans << endl;
    return 0;
}