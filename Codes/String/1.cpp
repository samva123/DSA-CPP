#include <iostream> 
using namespace std ;

int main(){
    int arr[5] = {10,20,30,40,50} ;

    //int *p = arr+1;
    int *q  = arr;

    cout << arr <<endl;
    cout << &arr<<endl ; 
    cout << &arr[0]<<endl;
    cout << *(arr+1)<<endl;
    cout << q << endl;
    cout << *q ;
    // cout << (++a)*(a++) ;


}