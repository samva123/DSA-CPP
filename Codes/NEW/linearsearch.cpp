#include<iostream>
using namespace std ;

int linearsearch( int arr[] , int n , int target){
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == target){
            return 1;
        }
 }
 return -1;
}

int main(){
    int arr[] = {23,34,56,54};
    int target = 34;
    int n = 4;

    int ans = linearsearch(arr , n , target);

    if(ans == -1){
        cout << "element not found";
    }
    else{
        cout << "found"<< endl;
    }
    cout << endl ;

    cout << arr[0];




}