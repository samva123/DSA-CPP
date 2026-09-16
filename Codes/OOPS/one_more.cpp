#include <iostream>
using namespace std;

int main(){
    // const int x = 5; // x is constant.
    // initialization can be done.
    // but we cant re-assign a value.
    // x = 10;
    // cout << x << endl;

    // 2. const with pointers
    // // const int *a = new int(2); // CONST data, NON-CONST pointer
    // int const *a = new int(2); // some as line no. 13.
    // cout << *a << endl;
    // // *a = 20; // cant change the
    // // cout << *a << endl;
    // int b = 20;
    // a = &b; // pointer itselft can be reassigned.
    // cout << *a << endl;


    // CONST Pointer, but NON-CONST data.
    // int *const a = new int(2);
    // cout << *a << endl;
    // *a = 20; // chal jayega
    // cout << *a << endl;
    // int b = 50;
    // a = &b; // nahi chalega, CONST pointer.

    // CONST pointer, CONST data
    // const int *const a = new int(10);
    // cout << *a << endl;
    // *a = 50;
    // int b= 100;
    // a = &b;
    return 0;
    return 0;

}

